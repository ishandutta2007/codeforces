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

#include <functional>
#include <limits>

template<typename T, bool T_integral = std::is_integral<T>::value>
struct line {
    static constexpr T infinity = std::numeric_limits<T>::has_infinity ?
        std::numeric_limits<T>::infinity() : std::numeric_limits<T>::max();

    T a, b;
    mutable T intersects_next = infinity;

    T evaluate(T x) const {
        return a * x + b;
    }

    static T div(const T &a, const T &b) {
        if constexpr (T_integral)
            return a / b - ((a ^ b) < 0 && (a % b));
        else
            return a / b;
    }

    T compute_intersection(const line<T> &o) const {
        if (a == o.a) return b > o.b ? infinity : -infinity;
        return div(o.b - b, a - o.a);
    }
};

bool compare_on_intersection = false;

template<typename T>
bool operator < (const line<T> &p, const line<T> &q) {
    if (compare_on_intersection)
        return p.intersects_next < q.intersects_next;

    return p.a != q.a ? p.a < q.a : p.b < q.b;
}

// {{{ data_structures/line }}}

#include <cassert>
#include <set>

template<typename T>
struct line_container : std::set<line<T>> {
    using typename std::set<line<T>>::iterator;

    bool set_boundary(iterator left, iterator right) {
        if (right == this->end()) {
            left->intersects_next = line<T>::infinity;
            return false;
        }

        left->intersects_next = left->compute_intersection(*right);
        return left->intersects_next >= right->intersects_next;
    }

    bool is_never_maximal(iterator y) {
        return y != this->begin() && set_boundary(prev(y), y);
    }

    // insert the line f(x) = a * x + b
    void insert_line(T a, T b) {
        auto [it, was_inserted] = this->insert({ a, b });

        if (!was_inserted)
            return;

        while (set_boundary(it, next(it)))
            this->erase(next(it));

        if (is_never_maximal(it)) {
            it = this->erase(it);
            set_boundary(prev(it), it);
        }

        while (it != this->begin() && is_never_maximal(prev(it))) {
            this->erase(prev(it));
            set_boundary(prev(it), it);
        }
    }

    // returns the maximum value at x0 among all inserted lines
    T maximum(T x0) {
        assert(!this->empty());
        compare_on_intersection = true;
        T res = this->lower_bound({ 0, 0, x0 })->evaluate(x0);
        compare_on_intersection = false;
        return res;
    }
};

#include <iostream>
using namespace std;

// {{{ data_structures/line_container }}}

// {{{ graphs/tree }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> b(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];

    tree<edge> tr(N, 0);
    re(tr, EDGE_LIST, 1);

    vector<int64_t> min_cost_path(N, 1e10);
    vector<line_container<int64_t>> leaf_paths(N);

    for (int u : tr.reverse_preorder) {
        bool has_child = false;

        tr.for_each_child(u, [&](edge e) {
            has_child = true;

            int child = e.get_nbr(u);

            if (leaf_paths[child].size() > leaf_paths[u].size())
                swap(leaf_paths[u], leaf_paths[child]);

            for (const line<int64_t> &l : leaf_paths[child])
                leaf_paths[u].insert_line(l.a, l.b);

            leaf_paths[child].clear();
        });

        if (!has_child)
            min_cost_path[u] = 0;
        else
            min_cost_path[u] = -leaf_paths[u].maximum(a[u]);

        leaf_paths[u].insert_line(-b[u], -min_cost_path[u]);
    }

    for (int u = 0; u < N; u++) {
        if (u) cout << " ";
        cout << min_cost_path[u];
    }
    cout << endl;

    return 0;
}