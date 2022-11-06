#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        bool yes=0;
        for(int i=1; i<=6; i++) {
            ll now=n-(21-i);
            if(now<0) continue;
            if(now%14==0) yes=1;
        }
        if(yes) puts("YES");
        else puts("NO");
    }
}