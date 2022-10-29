#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector< pair< pair< int, int >, int > > queries;
vector< pair< int, int > > segs;
vector< int > ans;
int n, q;
deque< int > diff, sum;
deque< pair< int, int > > lies;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    segs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
        segs[i].second += segs[i].first;
    }
    cin >> q;
    queries.resize(q);
    ans.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries.rbegin(), queries.rend());
    auto it = queries.begin();
    lies.push_back(make_pair(2000000001, 2000000001));
    diff.push_back(0);
    sum.push_back(0);
    for (int i = n - 1; i >= 0; --i) {
        int cur_max = segs[i].second;
        while (lies.front().first <= cur_max) {
            cur_max = max(lies.front().second, cur_max);
            lies.pop_front();
            diff.pop_front();
            sum.pop_front();
        }
        diff.push_front(lies.front().first - cur_max);
        lies.push_front(make_pair(segs[i].first, cur_max));
        int cur_sum = sum.front() + diff.front();
        sum.push_front(cur_sum);
        while (it != queries.end() && it->first.first - 1 == i) {
            int to = it->first.second - 1;
            //int from = it->first - 1;
            int l = -1, r = lies.size();
            int check = segs[to].first;
            while (l < r - 1) {
                int mid = (l + r) / 2;
                if (lies[mid].second >= check) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            ans[it->second] = sum.front() - sum[r];
            ++it;
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}