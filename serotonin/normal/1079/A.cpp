#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5,m=1e9+7;
int a[105];
int main()
{
    int n,k,i;
    cin >> n >> k;
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int t=0,u=0;
    for(i=0;i<105;i++) {
        t=max(t,a[i]);
        if(a[i]) u++;
    }
    int d=t/k;
    if(t%k) d++;
    int ans=(u*d*k)-n;
    printf("%d\n", ans);
}