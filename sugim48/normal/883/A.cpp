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
ll N,a,d;
int M;
ll t[110000];

int main(){
//	cin>>N>>M>>a>>d;
	scanf("%lld%d%lld%lld",&N,&M,&a,&d);
	rep(i,M) scanf("%lld",t+i);
	t[M] = a*N;
	sort(t,t+M+1);
	t[M+1] = 4e18;
	M++;

	ll one = d/a+1;
	int ti = 0;
	ll i = 1;
	ll ans = 0;
	while(ti<M || i<=N){
		ll x = min(t[ti],a*i);	//[x,x+d]
		if(i>N) x = t[ti];
		if(x == a*i){	//skip
			if(ti==M){
				ans += (N-i+1 + one-1)/one;
				break;
			}
			ll nt = t[ti];
			ll k = (nt-a*i)/(one*a);
			if(k>0){
				ans += k;
				i += k*one;
			}
		}
		x = min(t[ti],a*i);
		if(i>N) x = t[ti];
		while(ti<M && t[ti]<=x+d) ti++;
		i = (x+d)/a + 1;
		ans++;
	}
	cout<<ans<<endl;
}