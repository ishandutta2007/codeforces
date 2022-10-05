#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>

using namespace std;
bool comp(pair<int,int> a, pair<int, int> b){
    return a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(0);
    vector<int> a(6, 0);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int n;
    cin >> n;
    vector<pair<int,int>> points(n, {0, 0});
    vector<int> ip;
    int r = -INT_MAX;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        points[i] = {k - a[5], 5};
        r = max(r, k - a[5]);
        for (int j = 0; j < 6; ++j) {
            ip.push_back(k - a[j]);
        }
    }
    sort(ip.begin(), ip.end());
    make_heap(points.begin(), points.end(), comp);
    int ans = INT_MAX;
    for (int i = 0; i < ip.size(); ++i) {
        int l = ip[i];
        while(points[0].first < l) {
            pop_heap(points.begin(), points.end(), comp);
            while (points.back().first < l) {
                if (points.back().second == 0) {
                    cout << ans;
                    return 0;
                }
                points.back().first += a[points.back().second];
                points.back().second -= 1;
                points.back().first -= a[points.back().second];
                r = max(points.back().first, r);
            }
            push_heap(points.begin(), points.end(), comp);
        }
        ans = min(ans, r - l);
    }
    cout << ans;
}