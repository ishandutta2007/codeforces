#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

int a[69];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        scanf("%lld %lld", &n, &k);
        memset(a, 0, sizeof a);
        bool no = 0;
        for(int i=0; i<n; i++) {
            ll x;
            scanf("%lld", &x);
            for(int j=0; x; j++) {
                ll y = x % k;
                if(y) {
                    if(y>1) no=1;
                    else a[j]++;
                }
                x /= k;
            }
        }

        for(int i=0; i<69; i++) {
            if(a[i]>1) no=1;
        }

        if(no) puts("NO");
        else puts("YES");
    }
}