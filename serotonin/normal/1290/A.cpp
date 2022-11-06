#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5, lim=2e9;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        int ans=0;
        k=min(k,m-1);
        for(int i=0; i<=k; i++) {
            vector <int> v;
            for(int j=0; j<n-k; j++) {
                v.push_back(a[i+j]);
            }

            int cut=m-1-k;

            int now=lim, tot=n-k-1;
            for(int j=0; j<=cut; j++) {
                now=min(now, max(v[j], v[tot-(cut-j)]));
            }

            ans=max(ans, now);
        }

        printf("%d\n", ans);
    }
}