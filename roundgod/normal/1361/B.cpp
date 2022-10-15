#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,t,k[MAXN];
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
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;i++) scanf("%d",&k[i]);
        if(p==1)
        {
            printf("%d\n",n&1);
            continue;
        }
        sort(k+1,k+n+1,greater<int>());
        int pos=k[1],ans=0;
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt==0)
            {
                cnt++;
                pos=k[i];
                add(ans,pow_mod(p,k[i]));
            }
            else
            {
                bool f=true;
                while(pos>k[i])
                {
                    pos--;
                    cnt=cnt*p;
                    if(cnt>=n-i+1)
                    {
                        f=false;
                        break;
                    }
                }
                if(!f)
                {
                    for(int j=i;j<=n;j++) dec(ans,pow_mod(p,k[j]));
                    break;
                }
                else 
                {
                    cnt--;
                    dec(ans,pow_mod(p,k[i]));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}