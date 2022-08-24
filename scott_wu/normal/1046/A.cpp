#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct robot {
    int x, radius, iq;

    bool operator<(const robot &other) const {
        return radius > other.radius;
    }
};

int N, K;
vector<robot> robots;
map<int, tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>> iq_map;

int main() {
    scanf("%d %d", &N, &K);
    robots.resize(N);

    for (robot &r : robots)
        scanf("%d %d %d", &r.x, &r.radius, &r.iq);

    sort(robots.begin(), robots.end());
    long long total = 0;
    int iteration = 0;

    for (robot &r : robots) {
        for (int iq = r.iq - K; iq <= r.iq + K; iq++)
            if (iq_map.count(iq))
                total += iq_map[iq].order_of_key({r.x + r.radius, N}) - iq_map[iq].order_of_key({r.x - r.radius, -1});

        iq_map[r.iq].insert({r.x, iteration++});
    }

    printf("%lld\n", total);
}