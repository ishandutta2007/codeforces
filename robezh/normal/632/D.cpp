#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;

int n, m;
int num[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        if(num[i] < N) cnt[num[i]]++;
    }
    for(int i = m; i >= 1; i--) {
        for(int j = 2 * i; j <= m; j += i) {
            cnt[j] += cnt[i];
        }
    }
    int mx = 1;
    for(int i = 2; i <= m; i++) {
        if(cnt[mx] < cnt[i]) mx = i;
    }
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(mx % num[i] == 0) res.push_back(i);
    }
    cout << mx << " " << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";
}