#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;

typedef long long ll;

#define N 200010

char s[N];
int a[N], cnt[N];
vector <int> v;

int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    for(int i = 1; i <= n; i ++) a[i] = a[i-1] + (s[i]-'0');
    ll ans = 0;
    tr1::unordered_map <int, int> mp;
    int D = sqrt(n+1);
    if(D > 300) D = 300;
    for(int k = 1; k <= D; k ++) {
        mp.clear();
        for(int i = 0; i <= n; i ++) {
            int x = k*a[i]-i;
            ans += mp[x];
            mp[x] ++;
        }
    }
    int E = n / D;
    for(int d = 1; d <= E; d ++) {
        for(int r = 0; r < d; r ++) {
            for(int i = 0; i < v.size(); i ++) cnt[v[i]] = 0;
            v.clear();
            for(int i = r, j = r; j <= n; j += d) {
                while(j-i > D * d) {
                    cnt[a[i]] ++;
                    if(cnt[a[i]] == 1) v.push_back(a[i]);
                    i += d;
                }
                if(a[j] >= d) ans += cnt[a[j]-d];
            }
        }
    }
    cout << ans << endl;
}