#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

char s[sz];

int main()
{
    ll n,m,i,j,k,x,y,q;
    scanf("%s", s);
    ll l=strlen(s),one=-1,two=-1,f;
    f=0;
    for(i=0; i<l; i++) {
        if(s[i]=='[') f=1;
        else if(f && s[i]==':') {
            one=i;
            break;
        }
    }
    f=0;
    for(i=l-1; i>=0; i--) {
        if(s[i]==']') f=1;
        else if(f && s[i]==':') {
            two=i;
            break;
        }
    }
    ll ans=4;
    if(one<0 || two<0) puts("-1");
    else if(two<=one) puts("-1");
    else {
        for(i=one; i<two; i++) if(s[i]=='|') ans++;
        printf("%lld\n", ans);
    }
}