#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 155;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector <ll> a;
        a.push_back(-1);
        for(int i=0; i<n; i++) {
            scanf("%s", s);
            reverse(s, s+m);
            ll x = 0;
            for(int j=0; j<m; j++) if(s[j] == '1') x |= 1LL << j;
            a.push_back(x);
        }
        a.push_back(1LL << m);
        sort(a.begin(), a.end());
//        for(int i=0; i<a.size(); i++) printf("%lld ", a[i]);
//        puts("");

        ll who = (1LL << m) - n;
        who = (who + 1) >> 1;
//        printf("who %lld\n", who);
        for(int i=0; i+1 < a.size(); i++) {
            ll x = a[i+1] - a[i] - 1;
//            printf("x %lld\n", x);
            if(x >= who) {
                ll ans = a[i] + who;
                int ss[sz];
                for(int j=0; j<m; j++) {
                    if(ans & 1LL) ss[j] = 1;
                    else ss[j] = 0;
                    ans >>= 1;
                }
                reverse(ss, ss+m);
//                printf("ans ** \n");
                for(int j=0; j<m; j++) printf("%d", ss[j]);
                puts("");
                break;
            }
            who -= x;
//            printf("still who %lld\n", who);
        }
    }
}