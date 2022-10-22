#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int a[100010];
int dp[100010][2];
int s[100010];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        map<int, int> mp;
        mp[0] = 0;
        int S = 0;
        int dp = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S ^= a[i];
            int ndp = dp + (a[i] != 0);
            if (mp.find(S) != mp.end()) {
                ndp = min(ndp, i + mp[S] - 1);
            }
            if (mp.find(S) == mp.end()) {
                mp[S] = ndp - i;
            } else {
                mp[S] = min(mp[S], ndp - i);
            }
            dp = ndp;
        }
        printf("%d\n",dp);
    }
}