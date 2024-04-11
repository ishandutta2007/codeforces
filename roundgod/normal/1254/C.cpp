#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,cur,h;
ll area[MAXN];
vector<int> lhs,rhs;
bool cmp(int x,int y)
{
    return area[x]<area[y];
}
ll get_area(int i,int j,int k)
{
    printf("1 %d %d %d\n",i,j,k);
    fflush(stdout);
    ll A;
    scanf("%lld",&A);
    return A;
}
int get_sign(int i,int j,int k)
{
    printf("2 %d %d %d\n",i,j,k);
    fflush(stdout);
    int sgn;
    scanf("%d",&sgn);
    return sgn;
}
int get_next()
{
    int cur=2;
    for(int i=3;i<=n;i++)
    {
        if(get_sign(1,cur,i)<0) cur=i;
    }
    return cur;
}
int get_highest()
{
    int id=-1;
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        if(i==cur) continue;
        ll A=get_area(1,cur,i);
        area[i]=A;
        if(A>ans)
        {
            ans=A;
            id=i;
        }
    }
    return id;
}
void solve()
{
    for(int i=2;i<=n;i++)
    {
        if(i==cur||i==h) continue;
        int sgn=get_sign(1,h,i);
        if(sgn>0) lhs.push_back(i); else rhs.push_back(i);
    }
    printf("0");
    printf(" %d %d",1,cur);
    sort(rhs.begin(),rhs.end(),cmp);
    sort(lhs.begin(),lhs.end(),cmp); reverse(lhs.begin(),lhs.end());
    for(auto x:rhs) printf(" %d",x);
    printf(" %d",h);
    for(auto x:lhs) printf(" %d",x);
    printf("\n");
    fflush(stdout);
}
int main()
{
    scanf("%d",&n);
    cur=get_next();
    h=get_highest();
    solve();
    return 0;
}