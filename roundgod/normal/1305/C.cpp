#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],cnt[MAXN];
string str;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=0;i<(int)v.size();i++)
    {
        if(ans==0) break;
        int x=v[i]%m;
        for(int j=0;j<m;j++)
        {
            if(cnt[j]) ans=1LL*ans*(x-j+m)%m; 
        }
        cnt[x]++;
    }
    printf("%d\n",ans);
    return 0;
}