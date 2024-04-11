#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
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
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    int lb=0,rb=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            lb++;
        }
        else 
        {
            rb++;
            if(rb>lb) ans+=2;
        }
    }
    if(lb!=rb) puts("-1"); else printf("%d\n",ans);
    return 0;
}