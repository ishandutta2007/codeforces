// union_find {{{
#include <vector>
#include <numeric>
#include <iostream>

struct union_find {
    struct node {
        int root, rank, size;
        node (int id = 0) : root(id), rank(0), size(1) {}
    };

    mutable std::vector<node> data;

    union_find(int SZ = 0) : data(SZ) {
        iota(data.begin(), data.end(), 0);
    }

    int find(int i) const {
        if (i != data[i].root)
            data[i].root = find(data[i].root);
        return data[i].root;
    }

    bool is_root(int i) const {
        return i == find(i);
    }

    node& root_node(int i) const {
        return data[find(i)];
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (data[a].rank < data[b].rank)
            std::swap(a, b);

        data[b].root = a;
        data[a].size += data[b].size;
        if (data[a].rank == data[b].rank)
            data[a].rank++;

        return true;
    }

    friend void pr(const union_find& u) {
        std::cout << "{";
        bool first = 1;
        for (int i = 0; i < int(u.data.size()); i++) {
            if (u.is_root(i)) {
                if (!first) std::cout << ", ";
                else first = 0;
                std::cout << "[ " << i << " | rank=" << u.data[i].rank
                    << " size=" << u.data[i].size << " ]";
            }
        }
        std::cout << "}";
    }
};
// }}}

#include <vector>
#include <cassert>
using namespace std;

// {{{ data_structures/union_find }}}

int main() {
    int N;
    scanf("%d", &N);

    union_find uf(N);

    std::vector<pair<int, int>> redundant;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;

        if (!uf.unite(u, v))
            redundant.emplace_back(u, v);
    }

    std::vector<int> component_roots;

    for (int i = 0; i < N; i++)
        if (uf.is_root(i))
            component_roots.push_back(i);

    assert(redundant.size() + 1 == component_roots.size());

    printf("%d\n", redundant.size());

    for (int i = 0; i < redundant.size(); i++) {
        printf("%d %d %d %d\n",
                redundant[i].first + 1, redundant[i].second + 1,
                component_roots[i] + 1, component_roots[i + 1] + 1);
    }

    return 0;
}