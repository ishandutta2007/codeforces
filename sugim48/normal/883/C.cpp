#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll N,T,t0,n1,t1,p1,n2,t2,p2;
int main(){
	cin>>N>>T>>t0;
	cin>>n1>>t1>>p1;
	cin>>n2>>t2>>p2;

	ll inf = 1e18;

	ll ans = inf;

	for(ll c = 0;c<=N;c++){
		ll X = N-c;
		ll Y = T - t2*c;
		if(Y<0) continue;
		ll b;
		if(t0<=t1){
			b = 0;
		}else{
			double db = ((double)t0*X-Y)/(t0-t1);
			if(X<=Y/t0){
				b = 0;
			}else{
				if(db > X+10) continue;
				b = (t0*X-Y + t0-t1-1)/(t0-t1);
				if(t0*X-Y<=0) b = 0;
			}
		}
		if(b>X) continue;
		ll a = X-b;
		if(t0*a + t1*b > Y) continue;
		chmin(ans,((b+n1-1)/n1)*p1 + ((c+n2-1)/n2)*p2);
	}
	if(ans == inf) ans = -1;
	cout<<ans<<endl;
}