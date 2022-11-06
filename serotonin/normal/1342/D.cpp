#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz], c[sz];

vector <int> v[sz];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i=1; i<=k; i++) scanf("%d", &c[i]);

    int lo = 1, hi = n;
    while(lo < hi) {
        int m = (lo + hi) >> 1;

        for(int i=0; i<n; i++) {
            int j = i % m;
            v[j].push_back(a[i]);
        }

        bool yes = 1;
        for(int i=0; i<m; i++) {
            reverse(v[i].begin(), v[i].end());
            int j=0;
            for(int x : v[i]) {
                j++;
                if(c[x] < j) yes = 0;
            }
            v[i].clear();
        }

        if(yes) hi = m;
        else lo = m + 1;
    }

    int m = lo;
    printf("%d\n", m);
    for(int i=0; i<n; i++) {
        int j = i % m;
        v[j].push_back(a[i]);
    }

    for(int i=0; i<m; i++) {
        printf("%d", v[i].size());
        for(int x : v[i]) printf(" %d", x);
        puts("");
    }
}