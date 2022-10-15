#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%d%d",&n,&m,&k);
        k=min(k,m-1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=m-1;i++) v.push_back(max(a[i+1],a[n-(m-1-i)]));
        int len=m-k;
        int ans=-INF;
        for(int i=0;i+len-1<(int)v.size();i++)
        {
            int tmp=INF;
            for(int j=i;j<=i+len-1;j++) tmp=min(tmp,v[j]);
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}