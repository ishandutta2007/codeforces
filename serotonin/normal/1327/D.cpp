#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int ans, a[sz], c[sz];

bitset <sz> vis;

vector <int> ara;

void solve()
{
    int len = ara.size();
    vector <int> dvs;
    for(int i=1; i*i<=len; i++) {
        if(len%i==0) {
            dvs.push_back(i);
            dvs.push_back(len/i);
        }
    }
    for(int v : dvs) {
        for(int i=0; i<v; i++) {
            for(int j=i; j<len; j+=v) {
                if(j+v>=len) {
                    ans=min(ans, v);
                    break;
                }
                if(c[ara[j]]!=c[ara[j+v]]) break;
            }
        }
    }
    ara.clear();
}

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        for(int i=1; i<=n; i++) scanf("%d", &c[i]), vis[i]=0;

        ans=sz;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                while(!vis[i])
                    vis[i]=1, ara.push_back(i), i=a[i];
                solve();
            }
        }

        printf("%d\n", ans);
    }
}