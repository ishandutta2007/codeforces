#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x first
#define y second
//#define sf se.fi
//#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,ans;
pdd a[4],b[4],df;
double s,d,ts,td,eps = 1e-9;
bool val;
double dabs(double D){
	if(D<0.0)return -D;
	return D;
}
void f(int i){
	df = {b[i].y-a[i].y,a[i].x-b[i].x};
	a[i] = {b[i].x+df.x,b[i].y+df.y};
}
void cek(int i){
	double z,r1,r2;
	int cnt=0;
	z = sqrt((a[i].x-a[(i+1)%4].x)*(a[i].x-a[(i+1)%4].x) + (a[i].y-a[(i+1)%4].y)*(a[i].y-a[(i+1)%4].y));
	r1 = r2 = z;
	z = sqrt((a[i].x-a[(i+2)%4].x)*(a[i].x-a[(i+2)%4].x) + (a[i].y-a[(i+2)%4].y)*(a[i].y-a[(i+2)%4].y));
	if(r1>z)r1 = z,cnt++;
	if(r2<z)r2 = z,cnt++;
	z = sqrt((a[i].x-a[(i+3)%4].x)*(a[i].x-a[(i+3)%4].x) + (a[i].y-a[(i+3)%4].y)*(a[i].y-a[(i+3)%4].y));
	if(r1>z)r1 = z,cnt++;
	if(r2<z)r2 = z,cnt++;
	ts = r1, td = r2;
	if(cnt>1)val = 0;
}

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(tc,1,n){
    	rep(i,0,3)cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
    	ans = 16;
    	rep(i,0,3){
    		rep(j,0,3){
    			rep(k,0,3){
    				rep(o,0,3){
    					cek(0);
    					s = ts, d = td;
    					if(s>0.0001)val = 1;
    					else val = 0;
    					rep(tes,1,3){
    						cek(tes);
    						if(dabs(s-ts)>eps || dabs(d-td)>eps)val = 0;
						}
						if(val)ans = min(ans,i+j+k+o);
						f(3);
					}
					f(2);
				}
				f(1);
			}
			f(0);
		}
		if(ans==16)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
    return 0;
}