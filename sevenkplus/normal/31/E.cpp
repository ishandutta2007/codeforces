#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<string,ll> PSL;
#define fi first
#define se second
#define mp make_pair
int n;string s;ll f[20][20],p[20];string g[20][20];
PSL ff(int a,int b)
{
    if(g[a][b]!="")return mp(g[a][b],f[a][b]);
    if(a==0)
    {
        ll S=0;string T="";
        for(int i=2*n-b;i<2*n;i++)S=S*10+s[i]-'0',T+="M";
        return mp(g[a][b]=T,f[a][b]=S);
    }
    if(b==0)
    {
        ll S=0;string T="";
        for(int i=2*n-a;i<2*n;i++)S=S*10+s[i]-'0',T+="H";
        return mp(g[a][b]=T,f[a][b]=S);
    }
    PSL S1=ff(a-1,b),S2=ff(a,b-1);
    S1.fi="H"+S1.fi,S2.fi="M"+S2.fi;
    S1.se+=(s[n*2-a-b]-'0')*p[a-1],S2.se+=(s[n*2-a-b]-'0')*p[b-1];
    if(S1.se>S2.se)return mp(g[a][b]=S1.fi,f[a][b]=S1.se);
    else return mp(g[a][b]=S2.fi,f[a][b]=S2.se);
}
int main()
{
    cin>>n>>s;
    p[0]=1;for(int i=1;i<18;i++)p[i]=p[i-1]*10;
    cout<<ff(n,n).fi<<endl;
    return 0;
}