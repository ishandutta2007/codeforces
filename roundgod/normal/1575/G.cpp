#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int cnt[MAXN];
vector<int> fact[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,a[MAXN];
int ccnt[MAXN],res[MAXN],ans[MAXN];
vector<int> v,vv;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            fact[j].push_back(i);
    int sum=0;
    for(int d=n;d>=1;d--)
    {
        v.clear(),vv.clear();
        for(int i=d;i<=n;i+=d)
        {
            if(!cnt[a[i]]) 
                v.push_back(a[i]);
            cnt[a[i]]++;
        }
        for(auto x:v)
            for(auto g:fact[x])
            {
                if(!ccnt[g]) vv.push_back(g);
                ccnt[g]+=cnt[x];
            }
        sort(vv.begin(),vv.end());
        reverse(vv.begin(),vv.end());
        int ret=0;
        for(auto x:vv)
        {
            int num=1LL*ccnt[x]*ccnt[x]%MOD;
            add(res[x],num); 
            add(ret,1LL*x*res[x]%MOD);
            for(auto g:fact[x]) dec(res[g],res[x]);
        }
        for(auto x:vv) res[x]=0;
        add(ans[d],ret);
        for(auto x:v)
            for(auto g:fact[x])
                ccnt[g]-=cnt[x];
        for(int i=d;i<=n;i+=d) cnt[a[i]]--;
        add(sum,1LL*ans[d]*d%MOD);
        for(auto g:fact[d]) dec(ans[g],ans[d]);
    }
    printf("%d\n",sum);
    return 0;
}