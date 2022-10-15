#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define F first
#define S second
#define hash asokdo
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
P MOD=P(1000000007,998244353);
P BASE=P(19980826,19991020);
P hash[MAXN];
P pw[MAXN];
vector<P> pre[MAXN];
P find_hash(int i,int j)
{
    int rem=j%i;
    P p=pre[i][j/i];
    p.F=(1LL*p.F*pw[rem].F+hash[rem].F)%MOD.F;
    p.S=(1LL*p.S*pw[rem].S+hash[rem].S)%MOD.S;
    return p;
}
bool cmp(int i,int j)
{
    int l=min(i,j),r=k+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(find_hash(i,mid)==find_hash(j,mid)) l=mid; else r=mid;
    }
    if(r==k+1) return true;
    else if(str[(r-1)%i]<=str[(r-1)%j]) return true;
    else return false;
}
int main()
{
    pw[0]=P(1,1);
    for(int i=1;i<=500000;i++) 
    {
        pw[i].F=1LL*pw[i-1].F*BASE.F%MOD.F;
        pw[i].S=1LL*pw[i-1].S*BASE.S%MOD.S;
    }
    scanf("%d%d",&n,&k);
    cin>>str;
    hash[0]=P(0,0);
    for(int i=0;i<n;i++)
    {
        hash[i+1].F=(1LL*hash[i].F*BASE.F+(str[i]-'a'+1))%MOD.F;
        hash[i+1].S=(1LL*hash[i].S*BASE.S+(str[i]-'a'+1))%MOD.S;
    }
    for(int i=1;i<=min(n,k);i++)
    {
        P hsh=P(0,0);
        pre[i].push_back(hsh);
        for(int j=1;i*j<=k;j++)
        {
            hsh.F=(1LL*hsh.F*pw[i].F+hash[i].F)%MOD.F;
            hsh.S=(1LL*hsh.S*pw[i].S+hash[i].S)%MOD.S;
            pre[i].push_back(hsh);
        }
    }
    int cur=1;
    for(int i=2;i<=min(n,k);i++)
    {
        if(cmp(i,cur)) cur=i;
        //printf("i=%d cur=%d\n",i,cur);
    }
    //printf("cur=%d\n",cur);
    for(int i=0;i<k;i++) printf("%c",str[i%cur]);
    return 0;
}