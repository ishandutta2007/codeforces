#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

vector <ll> a;

int main()
{
    ll i,j,k,t,x,y,z,n,m,s;
    cin >> n >> s;
    for(i=0;i<n;i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll p=lower_bound(a.begin(), a.end(), s)-a.begin();
    if(n==1) {
        printf("%I64d\n", abs(s-a[0]));
    }
    else if(p==n/2) {
        if(a[p]==s) puts("0");
        else {
            printf("%I64d\n", abs(s-a[p]));
        }
    }
    else if(p>n/2) {
        x=0;
        for(j=n/2;j<p;j++) x+=s-a[j];
        printf("%I64d\n", x);
    }
    else {
        x=0;
        for(j=p;j<=n/2;j++) x+=a[j]-s;
        printf("%I64d\n", x);
    }
}