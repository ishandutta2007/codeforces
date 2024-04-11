#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector< tuple< int, int, int > > parties;
    vector< tuple< int, int, int, int > > actors;
    int n;
    cin >> n;
    parties.resize(n);
    vector< int > points;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        parties[i] = make_tuple(a, b, i);
        points.push_back(a);
        points.push_back(b);
    }
    int m;
    cin >> m;
    actors.resize(m);
    for (int i = 0; i < m; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        actors[i] = make_tuple(a, b, k, i);
        points.push_back(a);
        points.push_back(b);
    }
    vector< int > ans(n, -1);
    bool ok = true;
    sort(parties.begin(), parties.end());
    sort(actors.begin(), actors.end());
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    for (auto &x : parties) {
        get< 0 >(x) = lower_bound(points.begin(), points.end(), get< 0 >(x)) - points.begin();
        get< 1 >(x) = lower_bound(points.begin(), points.end(), get< 1 >(x)) - points.begin();
    }
    for (auto &x : actors) {
        get< 0 >(x) = lower_bound(points.begin(), points.end(), get< 0 >(x)) - points.begin();
        get< 1 >(x) = lower_bound(points.begin(), points.end(), get< 1 >(x)) - points.begin();
    }
    map< int, set< pair< int, int > > > all_points;
    vector< int > cnt(m);
    for (const auto &x : actors) {
        int a, b, id, k;
        tie(a, b, k, id) = x;
        cnt[id] = k;
    }
    auto gl_it = actors.begin();
    for (const auto &x : parties) {
        int a, b, id;
        tie(a, b, id) = x;
        while (gl_it != actors.end() && get< 0 >(*gl_it) <= a) {
            all_points[get< 1 >(*gl_it)].insert({get< 0 >(*gl_it), get< 3 >(*gl_it)});
            ++gl_it;
        }
        auto it = all_points.lower_bound(b);
        if (it != all_points.end()) { 
            auto val = *(it->second.begin());
            if (!(--cnt[val.second])) {
                it->second.erase(val);
                if (it->second.empty()) {
                    all_points.erase(it);
                }
            }
            ans[id] = val.second;
        } else {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " \n"[i == n - 1];
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}