#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
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
vector<int> v;
int main()
{
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=0;i<25;i++)
    {
        v.clear();
        int cnt=0;
        for(int j=1;j<=n;j++) 
        {
            if(a[j]&(1<<i)) cnt++;
            v.push_back(a[j]&((1<<i)-1));
        }
        sort(v.begin(),v.end());
        int parity=(1LL*cnt*(n-cnt))&1;
        int now=0;
        for(int j=n-1;j>=0;j--)
        {
            while(now<n&&v[now]+v[j]<(1<<i)) now++;
            if(now<j)
            {
                parity=parity+(j-now);
                parity&=1;
            }
        }
        if(parity) ans+=(1<<i);
    }
    printf("%d\n",ans);
    return 0;
}