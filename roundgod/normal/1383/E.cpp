#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN];
vector<int> v;
struct seg
{
    int sum[4*MAXN],len[4*MAXN];
    bool lazy[4*MAXN];
    int ladd[4*MAXN];
    void build(int k,int l,int r)
    {
        lazy[k]=false; sum[k]=0; ladd[k]=0; len[k]=r-l+1;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k)
    {
        sum[k]=sum[k*2];
        add(sum[k],sum[k*2+1]);
    }
    void clear(int k)
    {
        sum[k]=0;
        ladd[k]=0;
        lazy[k]=true;
    }
    void sadd(int k,int v)
    {
        add(sum[k],1LL*len[k]*v%MOD);
        add(ladd[k],v);
    }
    void pushdown(int k)
    {
        if(lazy[k])
        {
            for(int i=k*2;i<=k*2+1;i++) clear(i);
            lazy[k]=false;
        }
        if(ladd[k])
        {
            for(int i=k*2;i<=k*2+1;i++) sadd(i,ladd[k]);
            ladd[k]=0;
        }
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            pushdown(k);
            sadd(k,v);
            return;
        }
        int mid=(l+r)/2;
        pushdown(k);
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    void clr(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            clear(k);
            return;
        }
        int mid=(l+r)/2;
        pushdown(k);
        clr(k*2,l,mid,x,y); clr(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return sum[k];
        int mid=(l+r)/2;
        pushdown(k);
        int res=query(k*2,l,mid,x,y);
        add(res,query(k*2+1,mid+1,r,x,y));
        return res;
    }
}seg;
int main()
{
    cin>>str;
    int cnt1=0,cnt2=0;
    while(str.size()&&str.back()=='0') {cnt1++; str.pop_back();}
    reverse(str.begin(),str.end());
    while(str.size()&&str.back()=='0') {cnt2++; str.pop_back();}
    reverse(str.begin(),str.end());
    n=(int)str.size();
    if(!n)
    {
        printf("%d\n",cnt1);
        return 0;
    }
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(str[i]=='1') {v.push_back(cnt); cnt=0;}
        else cnt++;
    }
    dp[0]=1;
    seg.build(1,1,1000001);
    seg.update(1,1,1000001,1,1000001,1);
    int ans=1;
    for(int i=0;i<(int)v.size();i++)
    {
        dp[i+1]=seg.query(1,1,1000001,1,v[i]+1);
        add(ans,dp[i+1]);
        seg.clr(1,1,1000001,1,v[i]+1);
        seg.update(1,1,1000001,1,1000001,dp[i+1]);
    }
    ans=1LL*ans*(cnt1+1)%MOD*(cnt2+1)%MOD;
    printf("%d\n",ans);
    return 0;
}