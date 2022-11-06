#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[sz], b[sz];

int main()
{
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);

    int ans=0;
    for(int i=0; i<n; i++) {
        if(a[i]%p) {
            ans+=i;
            break;
        }
    }
    for(int i=0; i<m; i++) {
        if(b[i]%p) {
            ans+=i;
            break;
        }
    }
    cout << ans;
}