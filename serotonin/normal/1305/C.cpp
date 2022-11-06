#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];
vector <int> d[sz];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a,a+n);

    for(int i=0; i<n; i++) d[a[i]%m].push_back(a[i]);
    for(int i=0; i<m; i++) {
        if(d[i].size()>1) {
            puts("0");
            return 0;
        }
    }

    ll ans=1;
    for(int i=0; i<m; i++) {
        if(!d[i].size()) continue;
        for(int j=i+1; j<m; j++) {
            if(!d[j].size()) continue;
            ll x = abs(d[i][0] - d[j][0]);
            ans = (ans * x) % m;
        }
    }

    cout << ans;
}



//12, 21, m=10
//
//26 36, m=7
//
//5, 1