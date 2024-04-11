#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

char s[sz];
vector <ll> pos;

int main()
{
    ll i,j,k,x,y,z,n,m,a,b,e;
    scanf("%I64d %I64d", &n, &k);
    scanf("%s", s);
    x=0;
    for(i=0;i<n;i++) {
        if(s[i]=='(') {
            pos.push_back(i);
        }
        else {
            z=pos.size();
            s[pos[z-1]]='0';
            s[i]='0';
            x+=2;
            z--;
            pos.erase(pos.begin()+z);
        }
        if(x==n-k) break;
    }
    for(i=0;i<n;i++) {
        if(s[i]!='0') printf("%c", s[i]);
    }
    puts("");
}