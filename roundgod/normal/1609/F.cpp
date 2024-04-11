#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll ta[MAXN];
int a[MAXN];
int b[MAXN];
vector< pair<ll,int> > dis;
ll ans;
int tmp1[61],tmp2[61];
void solve_cnt(vector<P> &lhs,vector<P> &rhs)
{
    memset(tmp1,0,sizeof(tmp1));// minimum < current
    int s=0;
    ll tmp=ans;
    //maximum in the left
    int premax=-1,premin=-1;
    for(int i=0;i<(int)lhs.size();i++)
    {
        while(premax+1<(int)rhs.size()&&rhs[premax+1].F<=lhs[i].F) 
        {
            premax++;
            if(premax>premin) tmp1[b[rhs[premax].S]]++; else s++;
        }
        while(premin+1<(int)rhs.size()&&rhs[premin+1].S>=lhs[i].S) 
        {
            premin++;
            if(premin<=premax) s++,tmp1[b[rhs[premin].S]]--;
        }
        if(b[lhs[i].F]==b[lhs[i].S]) ans+=s;
        ans+=tmp1[b[lhs[i].F]];
    }
}
void solve(int l,int r)
{
    if(l==r)
    {
        ans++;
        return;
    }
    int mid=(l+r)/2;
    solve(l,mid); solve(mid+1,r);
    vector<P> lhs,rhs;
    int mini=INF,maxi=-INF;
    for(int i=mid;i>=l;i--) 
    {
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
        lhs.push_back(make_pair(maxi,mini));
    }
    mini=INF,maxi=-INF;
    for(int i=mid+1;i<=r;i++) 
    {
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
        rhs.push_back(make_pair(maxi,mini));
    }
    solve_cnt(lhs,rhs);
    swap(lhs,rhs);
    solve_cnt(lhs,rhs);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&ta[i]);
        dis.push_back(make_pair(ta[i],i));
    }
    sort(dis.begin(),dis.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(dis.begin(),dis.end(),make_pair(ta[i],i))-dis.begin()+1;
        b[a[i]]=__builtin_popcountll(ta[i]);
    }
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}