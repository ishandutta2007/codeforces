#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,I,a[MAXN];
map<int,int> cnt;
vector<int> v;
int sum[MAXN];
int main()
{
    scanf("%d%d",&n,&I);
    int to=(8*I/n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    if(to>=30||(1<<to)>=(int)cnt.size()) {puts("0"); return 0;}
    for(auto p:cnt) v.push_back(p.S);
    int need=(1<<to);
    int ans=n,cur=0;
    for(int i=0;i<need;i++) cur+=v[i];
    ans=min(ans,n-cur);
    for(int i=need;i<(int)v.size();i++)
    {
        cur+=v[i];
        cur-=v[i-need];
        ans=min(ans,n-cur);
    }
    printf("%d\n",ans);
    return 0;
}