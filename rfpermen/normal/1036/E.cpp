#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=1e3+5;
const int MOD=1000000000 + 7;
const ll INF=2e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,a[MAX],b[MAX],x[MAX],y[MAX],ans,tu,tv;
double u,v,px1,px2,px3,px4,py1,py2,py3,py4,eps = 1e-9;
set<piii> s;

inline void potong(){
	u = ((px1*py2-py1*px2)*(px3-px4)-(px1-px2)*(px3*py4-py3*px4))/((px1-px2)*(py3-py4)-(py1-py2)*(px3-px4));
	v = ((px1*py2-py1*px2)*(py3-py4)-(py1-py2)*(px3*py4-py3*px4))/((px1-px2)*(py3-py4)-(py1-py2)*(px3-px4));
}

inline double dabs(double d){
	if(d<0.0)return -d;
	return d;
}

inline bool cek(double d){
	return dabs(d-round(d))<=eps;
}

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>a[i]>>b[i]>>x[i]>>y[i];
    	ans+=__gcd(abs(a[i]-x[i]),abs(b[i]-y[i]))+1;
	}
	rep(i,1,n){
		px1 = a[i], px2 = x[i], py1 = b[i], py2 = y[i];
		rep(j,i+1,n){
			px3 = a[j], px4 = x[j], py3 = b[j], py4 = y[j];
			potong();
			if(	((u<=px1 && u>=px2)||(u>=px1 && u<=px2)) && ((v<=py1 && v>=py2)||(v>=py1 && v<=py2)) &&
			((u<=px3 && u>=px4)||(u>=px3 && u<=px4)) && ((v<=py3 && v>=py4)||(v>=py3 && v<=py4))){
				if(cek(u) && cek(v)){
					tu = round(u), tv = round(v);
					if(s.count({j,{tu,tv}}))continue;
					s.insert({j,{tu,tv}});
					ans--;
				}
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}