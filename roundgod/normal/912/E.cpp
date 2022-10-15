#include<bits/stdc++.h>
#define MAXN 20
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int p[MAXN];
ll k;
vector<int> pA,pB;
vector<ll> A,B;
bool check(ll x)
{
    int now=(int)B.size()-1;
    ll cnt=0;
    for(int i=0;i<(int)A.size();i++)
    {
        while(now>=0&&(x/B[now]<A[i]||A[i]*B[now]>x)) now--;
        if(now==-1) break;
        cnt+=(now+1);
    }
    return cnt>=k;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);
    for(int i=0;i<n;i++) if(i&1) pA.push_back(p[i]); else pB.push_back(p[i]);
    A.push_back(1); B.push_back(1);
    for(int i=0;i<(int)pA.size();i++)
    {
        int sz=(int)A.size();
        for(int j=0;j<sz;j++)
        {
            ll cur=A[j];
            while(INF/cur>=pA[i])
            {
                cur=cur*pA[i];
                if(cur>INF) break;
                A.push_back(cur);
            }
        }
    }
    for(int i=0;i<(int)pB.size();i++)
    {
        int sz=(int)B.size();
        for(int j=0;j<sz;j++)
        {
            ll cur=B[j];
            while(INF/cur>=pB[i])
            {
                cur=cur*pB[i];
                if(cur>INF) break;
                B.push_back(cur);
            }
        }
    }
    sort(A.begin(),A.end()); sort(B.begin(),B.end());
    scanf("%lld",&k);
    ll l=0,r=INF+1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    printf("%lld\n",r);
}