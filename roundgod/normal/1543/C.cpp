#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
int t;
ll a,b;
db c,m,p,v;
db eps=1e-6;
db solve_two(db c,db p)
{
    db ans=1;
    if(c<=v) ans+=c;
    else ans+=c*(solve_two(c-v,p+v));
    return ans;
}
db solve_three(db c,db m,db p)
{
    db ans=1;
    if(c<eps) return solve_two(m,p);
    if(m<eps) return solve_two(c,p);
    if(c<=v) ans+=c*(solve_two(m+c/2.0,p+c/2.0));
    else ans+=c*(solve_three(c-v,m+v/2.0,p+v/2.0));
    if(m<=v) ans+=m*(solve_two(c+m/2.0,p+m/2.0));
    else ans+=m*(solve_three(c+v/2.0,m-v,p+v/2.0));
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%Lf%Lf%Lf%Lf",&c,&m,&p,&v);
        printf("%.15Lf\n",solve_three(c,m,p));
    }
    return 0;
}