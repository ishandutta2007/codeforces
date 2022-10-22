#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n , d;
pair<int , int> fd[N];
long long sum[N];

int main() {
    cin >> n >> d;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> fd[i].first >> fd[i].second;
    }
    sort(fd , fd + n);
    // sum_i => sum of fd.second in [0 , i).
    for (int i = 0 ; i < n ; ++ i) {
        sum[i + 1] = sum[i] + fd[i].second;
    }
    long long res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int l = i , r = n;
        // calculate the first fd that fd.first >= fd[i].first + d
        while (l < r) {
            int mid = (l + r) / 2;
            if (fd[mid].first >= fd[i].first + d) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        res = max(res , sum[r] - sum[i]);
    }
    cout << res << endl;
}