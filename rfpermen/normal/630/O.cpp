#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
#define ot cout<<x+dx*cs+dy*sn<<" "<<y-dx*sn+dy*cs<<endl;
double x,y,vx,vy,a,b,c,d,dx,dy,rt,sn,cs;

int main(){
	cout<<fixed<<setprecision(12);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>vx>>vy>>a>>b>>c>>d;
    rt = atan2(vx,vy);
//    cout<<rt/pi*180.0<<endl;
    sn = sin(rt), cs = cos(rt);
//    cout<<sn<<" "<<cs<<endl;
    dx = 0, dy = b; ot
    dx = -a/2, dy = 0; ot
    dx = -c/2, dy = 0; ot
    dx = -c/2, dy = -d; ot
    dx = c/2, dy = -d; ot
    dx = c/2, dy = 0; ot
    dx = a/2, dy = 0; ot
    return 0;
}