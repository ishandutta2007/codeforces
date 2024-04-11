// trie {{{
#include <array>
#include <vector>
#include <cassert>
#include <queue>

template<int MIN_CHAR, int SIGMA>
struct trie {
    struct node {
        int depth;
        std::array<int, SIGMA> child_links;

        int dict_index = -1;

        int suffix_link = 0;
        int dict_suffix_link = 0;
        int count_suffixes_in_dict = 0;

        node(int depth_) : depth(depth_) {
            child_links.fill(0);
        }
    };

    std::vector<node> data;
    std::vector<int> dictionary_word_links;

    int& child_link(int loc, int c) { return data[loc].child_links[c - MIN_CHAR]; }
    int child_link(int loc, int c) const { return data[loc].child_links[c - MIN_CHAR]; }

    int dict_proper_suffix_link(int loc) const {
        return data[data[loc].suffix_link].dict_suffix_link;
    }

    trie() : data(1, node(0)) {}

    template<typename InputIterator>
    trie(InputIterator first, InputIterator last) : data(1, node(0)) {
        for (InputIterator iter = first; iter != last; iter++)
            add_dictionary_word(iter->begin(), iter->end());
        build_suffix_link_tree();
    }

private:

    template<typename InputIterator>
    void add_dictionary_word(InputIterator first, InputIterator last) {
        int loc = 0;
        for (InputIterator iter = first; iter != last; iter++) {
            int c = *iter;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);

            if (!child_link(loc, c)) {
                child_link(loc, c) = int(data.size());
                data.push_back(node(data[loc].depth + 1));
            }
            loc = child_link(loc, c);
        }
        if (data[loc].count_suffixes_in_dict == 0) {
            data[loc].dict_suffix_link = loc;
            data[loc].dict_index = int(dictionary_word_links.size());
        }
        data[loc].count_suffixes_in_dict++;
        dictionary_word_links.push_back(loc);
    }

    std::vector<std::vector<int>> children;
    std::vector<std::pair<int, int>> dfs_ranges;
    void build_suffix_link_tree() {
        children.resize(int(data.size()));

        std::queue<int> bfs;
        for (int child : data[0].child_links)
            if (child) bfs.push(child);
        for (; !bfs.empty(); bfs.pop()) {
            int loc = bfs.front();
            int parent = data[loc].suffix_link;

            children[parent].push_back(loc);
            if (data[loc].dict_suffix_link == 0)
                data[loc].dict_suffix_link = data[parent].dict_suffix_link;
            data[loc].count_suffixes_in_dict += data[parent].count_suffixes_in_dict;

            for (int c = MIN_CHAR; c < MIN_CHAR + SIGMA; c++) {
                int &trie_child = child_link(loc, c);
                if (trie_child) {
                    bfs.push(trie_child);
                    data[trie_child].suffix_link = child_link(parent, c);
                } else trie_child = child_link(parent, c);
            }
        }

        dfs_ranges.resize(data.size());

        int visited = 0;
        auto dfs = [&](auto self, int loc) -> void {
            dfs_ranges[loc].first = visited++;
            for (int child : children[loc])
                self(self, child);
            dfs_ranges[loc].second = visited;
        };
        dfs(dfs, 0);
    }

    template<typename V>
    void copy_results_for_duplicate_dictionary_entries(std::vector<V> &results) const {
        for (int dict_index = 0; dict_index < int(dictionary_word_links.size()); dict_index++) {
            int loc = dictionary_word_links[dict_index];
            if (data[loc].dict_index != dict_index)
                results[dict_index] = results[data[loc].dict_index];
        }
    }

public:

    /* Processes the given text and returns the number of matches of each dictionary word.
     * Linear in text length and the number of dictionary words.
     */
    template<typename InputIterator>
    std::vector<int> count_matches(InputIterator first, InputIterator last) const {
        std::vector<int> count(dictionary_word_links.size());
        std::vector<std::vector<int>> found_with_length;

        auto record_match = [&](int loc, int quantity) {
            int dict_index = data[loc].dict_index;
            if (dict_index == -1) return;

            if (count[dict_index] == 0) {
                if (data[loc].depth >= found_with_length.size())
                    found_with_length.resize(data[loc].depth + 1);
                found_with_length[data[loc].depth].push_back(loc);
            }
            count[dict_index] += quantity;
        };

        int loc = 0;
        for (InputIterator iter = first; iter != last; iter++) {
            int c = *iter;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);

            loc = child_link(loc, c);
            record_match(data[loc].dict_suffix_link, 1);
        }

        for (int match_length = int(found_with_length.size()) - 1; match_length > 0; match_length--) {
            for (int match_loc : found_with_length[match_length])
                record_match(dict_proper_suffix_link(match_loc), count[data[match_loc].dict_index]);
        }

        copy_results_for_duplicate_dictionary_entries(count);
        return count;
    }

    /* Returns the starting index of every match of each dictionary word.
     * Linear in the text length, number of dictionary words, and total number of matches.
     */
    template<typename InputIterator>
    std::vector<std::vector<int>> indices_of_matches(InputIterator first, InputIterator last) const {
        std::vector<std::vector<int>> indices(int(dictionary_word_links.size()));

        int loc = 0;
        int index = 0;
        for (InputIterator iter = first; iter != last; iter++) {
            int c = *iter;
            index++;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);

            loc = child_link(loc, c);
            for (int par = data[loc].dict_suffix_link; par != 0; par = dict_proper_suffix_link(par)) {
                indices[data[par].dict_index].push_back(index + 1 - data[par].depth);
            }
        }

        /* Notable fact: before duplication, the total number of matches is at most
         * (text length) * (number of distinct dictionary word lengths), which is
         * O(text length * sqrt(sum of dictionary word lengths)).
         */
        copy_results_for_duplicate_dictionary_entries(indices);
        return indices;
    }

    /* Returns the total number of matches over all dictionary words.
     * Duplicate dictionary entries each contribute to the total match count.
     * Linear in the text length.
     */
    template<typename InputIterator>
    int64_t count_total_matches(InputIterator first, InputIterator last) const {
        int64_t count = 0;

        int loc = 0;
        for (InputIterator iter = first; iter != last; iter++) {
            int c = *iter;
            assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);

            loc = child_link(loc, c);
            count += data[loc].count_suffixes_in_dict;
        }

        return count;
    }
};
// }}}

// tree {{{
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

struct edge {
    int u_xor_v;

    edge() : u_xor_v(0) {}

    edge(int _u_xor_v) : u_xor_v(_u_xor_v) {}

    int get_nbr(int u) const {
        assert(u_xor_v);
        return u ^ u_xor_v;
    }
};

template<typename Data>
struct edge_with_data : edge {
    Data data;

    edge_with_data() : edge() {}

    edge_with_data(int _u_xor_v, Data _data) : edge(_u_xor_v), data(_data) {}
};

enum TreeInputFormat { EDGE_LIST, PARENT_LIST };
template<typename Edge>
struct tree {
    int V, root;
    std::vector<std::vector<Edge>> neighbors;

    std::vector<int> parent, depth, subtree_size, preorder, reverse_preorder;

    tree() : V(0), root(-1) {}

    tree(int _V, int _root) : V(_V), root(_root), neighbors(V) {}

    void add_edge(int u, int v, Edge e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.u_xor_v = u ^ v;
        neighbors[u].push_back(e);
        neighbors[v].push_back(e);
    }

    const Edge& parent_edge(int u) const {
        assert(u != root);
        return neighbors[u].front();
    }

    template<typename Function>
    void for_each_child(int u, Function fn) const {
        for (int i = u != root; i < int(neighbors[u].size()); i++)
            fn(neighbors[u][i]);
    }

    static void DefaultEdgeDataReader(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataReader = void(*)(Edge&)>
    friend void re(tree &t, TreeInputFormat Format, int FirstIndex,
            EdgeDataReader read = DefaultEdgeDataReader) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            std::cin >> u, u -= FirstIndex;
            if (Format == PARENT_LIST) v = i + 1;
            else std::cin >> v, v -= FirstIndex;
            Edge e;
            read(e);
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void reroot(int _root) {
        root = _root;
        init();
    }

    void init() {
        parent.resize(V), depth.resize(V), subtree_size.resize(V);

        parent[root] = -1;
        depth[root] = 0;

        traverse(root);

        for (int u = 0; u < V; u++) {
            sort(neighbors[u].begin(), neighbors[u].end(), [&](const Edge &a, const Edge &b) {
                return subtree_size[a.get_nbr(u)] > subtree_size[b.get_nbr(u)];
            });
        }

        preorder.clear();
        build_preorder(root);

        reverse_preorder = preorder;
        std::reverse(reverse_preorder.begin(), reverse_preorder.end());
    }

    void traverse(int u) {
        subtree_size[u] = 1;
        for (Edge e : neighbors[u]) {
            int v = e.get_nbr(u);
            if (v == parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subtree_size[u] += subtree_size[v];
        }
    }

    void build_preorder(int u) {
        preorder.push_back(u);
        for_each_child(u, [&](Edge e) { build_preorder(e.get_nbr(u)); });
    }

    static void DefaultEdgeDataWriter(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataWriter = void(*)(Edge&)>
    friend void pr(const tree& t, EdgeDataWriter write = DefaultEdgeDataWriter) {
        std::cout << "{V=" << t.V << " root=" << t.root << " |";
        for (int u = 0; u < t.V; u++) {
            std::cout << " " << u << "--{";
            t.for_each_child(u, [&](Edge e) {
                std::cout << "(ch=" << e.get_nbr(u);
                write(e);
                std::cout << ")";
            });
            std::cout << "}";
        }
        std::cout << "}";
    }
};
// }}}

// sqrt_tree_point_query {{{
#include <vector>
#include <cassert>

template<typename T, typename CommutativeOperation>
struct sqrt_tree_point_query {
    int SZ;
    T t_identity;
    CommutativeOperation TT;

    int SQRT;
    std::vector<T> data;
    std::vector<T> block_data;

    sqrt_tree_point_query() {}

    sqrt_tree_point_query(int _SZ, T _t_identity, CommutativeOperation _TT)
            : SZ(_SZ), t_identity(_t_identity), TT(_TT) {
        SQRT = 0;
        while (SQRT * SQRT < SZ)
            SQRT++;

        data.assign(SZ, t_identity);
        block_data.assign(SQRT, t_identity);
    }

    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[i] = fn(i);
    }

public:
    // Replaces the current value at index i with TT(current value, v)
    void add(int i, T v) {
        data[i] = TT(data[i], v);
    }

    void add_to_range(int first, int last, T v) {
        if (last - first < SQRT) {
            for (int i = first; i < last; i++)
                data[i] = TT(data[i], v);
            return;
        }

        const int first_block = (first + SQRT - 1) / SQRT;
        const int last_block  = last / SQRT;

        for (int i = first; i < first_block * SQRT; i++)
            data[i] = TT(data[i], v);

        for (int block = first_block; block < last_block; block++)
            block_data[block] = TT(block_data[block], v);

        for (int i = last_block * SQRT; i < last; i++)
            data[i] = TT(data[i], v);
    }

    T read(int i) const {
        return TT(data[i], block_data[i / SQRT]);
    }
};
// }}}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<string> names(N);
    for (int i = 0; i < N; i++)
        cin >> names[i];

    vector<int> L(Q), R(Q), K(Q);

    vector<vector<int>> queries(N);

    vector<vector<int>> subtract(N), add(N);

    for (int q = 0; q < Q; q++) {
        cin >> L[q] >> R[q] >> K[q];
        --L[q], --R[q], --K[q];

        if (names[K[q]].size() > 300u) {
            queries[K[q]].push_back(q);
        } else {
            subtract[L[q]].push_back(q);
            add[R[q]].push_back(q);
        }
    }

    vector<int64_t> ans(Q);

    trie<'a', 26> tr(names.begin(), names.end());

    vector<int64_t> prefixes(N + 1);

    for (int i = 0; i < N; i++) {
        if (queries[i].empty())
            continue;

        vector<int> matches = tr.count_matches(names[i].begin(), names[i].end());

        for (int j = 0; j < N; j++)
            prefixes[j + 1] = prefixes[j] + matches[j];

        for (int q : queries[i])
            ans[q] = prefixes[R[q] + 1] - prefixes[L[q]];
    }

    const int V = int(tr.data.size());

    tree<edge> suffix_link_tree(V, 0);

    for (int i = 1; i < V; i++)
        suffix_link_tree.add_edge(i, tr.data[i].suffix_link);

    suffix_link_tree.init();

    vector<int> preorder_index(V);

    for (int i = 0; i < V; i++)
        preorder_index[suffix_link_tree.preorder[i]] = i;

    sqrt_tree_point_query st(V, 0, plus<int>());

    auto sum_trie_path = [&](int w) {
        int64_t res = 0;

        int loc = 0;
        for (char c : names[w]) {
            loc = tr.child_link(loc, c);
            res += st.read(preorder_index[loc]);
        }

        return res;
    };

    for (int i = 0; i < N; i++) {
        for (int q : subtract[i])
            ans[q] -= sum_trie_path(K[q]);

        int v = tr.dictionary_word_links[i];
        st.add_to_range(preorder_index[v], preorder_index[v] + suffix_link_tree.subtree_size[v], 1);

        for (int q : add[i])
            ans[q] += sum_trie_path(K[q]);
    }

    for (int64_t v : ans)
        cout << v << "\n";

    return 0;
}