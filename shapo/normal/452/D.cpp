#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

int
main()
{
    int k, n[3], t[3];
    cin >> k;
    for (int i = 0; i < 3; ++i) {
        cin >> n[i];
    }
    for (int j = 0; j < 3; ++j) {
        cin >> t[j];
    }
    vector< queue< int > > q;
    q.resize(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            q[i].push(0);
        }
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
        int allTimes[3] = {};
        for (int j = 0; j < 3; ++j) {
            allTimes[j] = q[j].front();
            q[j].pop();
        }
        int nextTime = *max_element(allTimes, allTimes + 3);
        res = max(res, nextTime + t[0] + t[1] + t[2]);
        for (int j = 0; j < 3; ++j) {
            q[j].push(nextTime + t[j]);
        }
    }
    cout << res << '\n';
    return 0;
}