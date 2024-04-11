#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
ll maxi[MAXN];
vector<ll> v;
int main()
{
    scanf("%d%d",&n,&m);
    int cur=n;
    bool f=true;
    ll s=0,sum=0;
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
        maxi[i]=max(maxi[i-1],s+x);
        if(s+x>n) f=false;
        s++;
        sum+=x;
    }
    if(!f||sum<n) puts("-1");
    else
    {
        vector<int> ans;
        int need=n-maxi[m];
        for(int i=0;i<m-1;i++) ans.push_back(i+1);
        ans.push_back(n-v.back()+1);
        for(int i=m-2;i>=0;i--)
        {
            if(ans[i]+v[i]>=ans[i+1]) break;
            ans[i]=ans[i+1]-v[i];
        }
        for(auto x:ans) printf("%d ",x);
    }
    
    return 0;
}