#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, b[200010];
map <int, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i ++) {
        scanf("%d", &x);
        if(mp.count(x)) {
            b[mp[x]] ++;
            b[i] --;
        }
        else mp[x] = i;
    }
    for(int i = 1; i <= n; i ++) b[i] += b[i-1];
    int ans = 1;
    for(int i = 1; i < n; i ++) if(!b[i]) (ans <<= 1) %= mod;
    printf("%d\n", ans);
}