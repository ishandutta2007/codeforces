#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

char s[sz],t[sz];

int main()
{
    ll i,j,k,x,y,z,n,m,a,b,c;
    scanf("%I64d %I64d", &n, &m);
    scanf("%s %s", s, t);
    if(n-1>m) {
        puts("NO");
        return 0;
    }

    ll p=-1;
    for(i=0;i<n;i++) {
        if(s[i]=='*') {
            p=i;
            break;
        }
    }

    ll f=1;
    if(p==-1) {
        if(strcmp(s,t)==0) puts("YES");
        else puts("NO");
        return 0;
    }

    for(i=0;i<p;i++) {
        if(s[i]!=t[i]) f=0;
    }
    for(i=n-1;i>p;i--) {
        if(s[i]!=t[m-1]) f=0;
        m--;
    }

    if(f==1) puts("YES");
    else puts("NO");
}