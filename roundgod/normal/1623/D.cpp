#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,r1,c1,r2,c2,p;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int get_lcm(int x,int y)
{
    return x*y/__gcd(x,y);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d%d",&n,&m,&r1,&c1,&r2,&c2,&p);
        p=1LL*p*pow_mod(100,MOD-2)%MOD;
        int dx=1,dy=1,x=r1,y=c1;
        vector<int> v;
        int period=get_lcm(2*(n-1),2*(m-1));
        for(int i=0;i<period;i++)
        {
            if(x==r2||y==c2) v.push_back(1); else v.push_back(0);
            if(x+dx>n||x+dx<1) dx=-dx;
            if(y+dy>m||y+dy<1) dy=-dy;
            x+=dx; y+=dy; 
        }
        
        vector<int> dp(period+1,0);
        int cf=1;
        for(int i=period-1;i>=0;i--)
        {
            if(!v[i]) {dp[i]=dp[i+1]; add(dp[i],1);}
            else 
            {
                dp[i]=1LL*(MOD+1-p)*(dp[i+1]+1)%MOD;
                cf=1LL*cf*(MOD+1-p)%MOD;
            }
        }
        
        printf("%d\n",1LL*dp[0]*pow_mod(MOD+1-cf,MOD-2)%MOD);
    }
    return 0;
}