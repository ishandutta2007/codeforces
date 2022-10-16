#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int sz;
double w,h,b,a,px1,px2,px3,px4,py1,py2,py3,py4,u,v,ans;
vector<pair<double,double> > z;

void potong(){
	u = ((px1*py2-py1*px2)*(px3-px4)-(px1-px2)*(px3*py4-py3*px4))/((px1-px2)*(py3-py4)-(py1-py2)*(px3-px4));
	v = ((px1*py2-py1*px2)*(py3-py4)-(py1-py2)*(px3*py4-py3*px4))/((px1-px2)*(py3-py4)-(py1-py2)*(px3-px4));
	if(	((u-EPS<=px1 && u+EPS>=px2)||(u+EPS>=px1 && u-EPS<=px2)) && ((v-EPS<=py1 && v+EPS>=py2)||(v+EPS>=py1 && v-EPS<=py2)) &&
	((u-EPS<=px3 && u+EPS>=px4)||(u+EPS>=px3 && u-EPS<=px4)) && ((v-EPS<=py3 && v+EPS>=py4)||(v+EPS>=py3 && v-EPS<=py4)))z.pb({u,v});
}

int main(){
	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>w>>h>>a;
    if(w<h)swap(w,h);
    if(a>90.0)a = 180.0-a;
    a = a*pi/180.0;
    w/=2.0, h/=2.0;
	px1 = px2 = -w, py1 = -h, py2 = h;
	px3 = px1*cos(a)-py1*sin(a), py3 = px1*sin(a)+py1*cos(a);
	px4 = px2*cos(a)-py2*sin(a), py4 = px2*sin(a)+py2*cos(a);
	potong();
	px1 = w, px2 = -w, py1 = -h, py2 = -h;
	potong();
	px3 = px1*cos(a)-py1*sin(a), py3 = px1*sin(a)+py1*cos(a);
	px4 = px2*cos(a)-py2*sin(a), py4 = px2*sin(a)+py2*cos(a);
	potong();
	px1 = -w, px2 = w, py1 = h, py2 = h;
	potong();
	px1 = w, px2 = w, py1 = -h, py2 = h;
	potong();
	px3 = px1*cos(a)-py1*sin(a), py3 = px1*sin(a)+py1*cos(a);
	px4 = px2*cos(a)-py2*sin(a), py4 = px2*sin(a)+py2*cos(a);
	potong();
	px1 = -w, px2 = w, py1 = h, py2 = h;
	potong();
	px3 = px1*cos(a)-py1*sin(a), py3 = px1*sin(a)+py1*cos(a);
	px4 = px2*cos(a)-py2*sin(a), py4 = px2*sin(a)+py2*cos(a);
	potong();
	px1 = w, px2 = -w, py1 = -h, py2 = -h;
	potong();
	px1 = px2 = -w, py1 = -h, py2 = h;
	potong();
	sz = z.size();
//	cout<<sz<<endl;
	z.pb(z[0]);
	rep(i,1,sz){
		ans+=z[i].fi*z[i-1].se-z[i].se*z[i-1].fi;
//		cout<<z[i].fi<<' '<<z[i].se<<endl;
	}
	cout<<fabs(ans/2.0)<<endl;
	return 0;
}