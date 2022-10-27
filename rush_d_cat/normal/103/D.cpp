#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;


#define N 300005
typedef long long LL;

int n, q, lim;
map< pair<int, int>, LL > mp;
LL w[N];
vector<int> v[N];
LL a[N], b[N], dp[N];

int main()
{
    scanf("%d", &n);  lim = (int)sqrt(n);
    
    for (int i = 1; i <= n; i ++) 
    {
        scanf("%lld", &w[i]);
    }
    scanf("%d", &q);

    for (int i = 1; i <= q; i ++) 
    {
        scanf("%lld %lld", &a[i], &b[i]);
        if (b[i] <= lim) v[ b[i] ].push_back(a[i]);
    }


    for (int i = 1; i <= lim; i ++) {
        if ( v[i].size() ) {
            for (int j = n; j >= 1; j --) {
                dp[j] = ((j + i <= n) ? dp[j + i] : 0) + w[j];
            }
            for (int j = 0; j < v[i].size(); j ++) {
                mp[ make_pair(v[i][j], i) ] = dp[ v[i][j] ];
            }
        }
    }

    for (int i = 1; i <= q; i ++) {
        if (b[i] <= lim) {
            printf("%I64d\n", mp[make_pair(a[i], b[i])]);
            //cout << mp[make_pair(a[i], b[i])] << endl;
        } else {
            LL ans = 0;
            for (int j = a[i]; j <= n; j += b[i]) {
                ans += w[j];
            }
            //cout << ans << endl;
            printf("%I64d\n", ans);
        }
    }


}