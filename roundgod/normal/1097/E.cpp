#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int t,n;
vec a,dp,rec;
mat ans;
void solve()
{
    int sz=(int)a.size();
    if(sz==0) return;
    int k=1;
    while((k+1)*(k+2)<=2*sz) k++;
    dp.resize(sz);rec.resize(sz);
    fill(dp.begin(),dp.end(),INF);
    for(int i=0;i<sz;i++) 
    {
        rec[i]=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        dp[rec[i]]=a[i];
    }
    int res=lower_bound(dp.begin(),dp.end(),INF)-dp.begin();
    if(res>k)
    {
        vector<int> ret;ret.clear();
        int now=res-1;
        for(int i=sz-1;i>=0;i--)
        {
            if(rec[i]==now) 
            {
                ret.push_back(a[i]);
                now--;
            }
        }
        reverse(ret.begin(),ret.end());
        ans.push_back(ret);
        vector<int> rem;rem.clear();
        now=0;
        for(int i=0;i<sz;i++) 
        {
            if(now<res&&a[i]==ret[now]) now++;
            else rem.push_back(a[i]);
        }
        a=rem;
        solve();
    }
    else
    {
        int SZ=ans.size();
        ans.resize(SZ+k);
        for(int i=0;i<sz;i++) ans[SZ+rec[i]].push_back(a[i]);
        return;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        scanf("%d",&n);
        a.resize(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        solve();
        int cnt=0;
        for(int i=0;i<(int)ans.size();i++) if(ans[i].size()) cnt++;
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
        {
            printf("%d ",(int)ans[i].size());
            for(int j=0;j<(int)ans[i].size();j++) printf("%d ",ans[i][j]);
            puts("");
        }
    }
    return 0;
}