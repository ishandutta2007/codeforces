#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define ii pair<ll,ll>
#define all(x) x.be,x.ee
#define ld long double
#define e '\n'
#define sp ' '
#define pb push_back
#define po pop_back()
#define up upper_bound
#define lo lower_bound
#define in insert
#define mk make_pair
#define er erase
#define R return
#define se second
#define co continue
#define fi first
#define fr front()
#define ba back()
#define si size()
#define em empty()
#define be begin()
#define ee end()
#define mod 1000000007
#define eb 0.000000001
#define Abs(x) max(x,-x)

int n,x,y,ans;
vector<pair<int,int>> v;
vector<ii> l;
map<pair<ii,ii>,bool> vis;

ii simplify(ii x)
{
    if (x.fi == 0) return mk(0,1);
    if (x.se == 0) return mk(1,0);
    ll g = __gcd(Abs(x.fi),Abs(x.se));
    return mk(x.fi/g,x.se/g);
}

ll lcm(ll a,ll b){
    R a*b/__gcd(a,b);
}
pair<ii,bool> f(pair<int,int> a,pair<int,int> b){
    pair<ii,bool> res;
    ii p1,p2;
    ll t1,t2,g,t3,t4;
    t1=b.se-a.se;
    t2=b.fi-a.fi;
if (t1<0 && t2<0)t1=-t1,t2=-t2;
if (t1<0 && t2>0)t1=-t1,t2=-t2;

    p1 = simplify(mk(t1,t2));
    t3=(b.se*t2-t1*b.fi);
    t4=t2;
    if (t4==0)
        t3=a.fi,t4=1;

if (t3<0 && t4<0)t3=-t3,t4=-t4;
if (t3<0 && t4>0)t3=-t3,t4=-t4;
    p2 = simplify(mk(t3,t4));
    res.se=1;
    res.fi=p1;
    if(vis[mk(p1,p2)]) res.se=0;
    vis[mk(p1,p2)]=1;
    R res;
}
int solve(ii a,ii b){
    return (a.fi*b.se != a.se*b.fi);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        v.pb(mk(x,y));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<ii,bool> temp=f(v[i],v[j]);
            if(temp.se) l.pb(temp.fi);
        }
    }
    for(int i=0;i<l.si;i++){
        for(int j=i+1;j<l.si;j++) ans+=solve(l[i],l[j]);
    }
    printf("%d",ans);
    R 0;
}