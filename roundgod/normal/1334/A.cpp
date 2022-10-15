#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,y,xx,yy;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        bool f=true;
        x=y=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&xx,&yy);
            if(xx<x||yy<y||yy-y>xx-x) f=false;
            x=xx; y=yy;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}