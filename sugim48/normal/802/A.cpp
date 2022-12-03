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
int N,K;
int a[80];
set<int> now;
int main(){
	cin>>N>>K;
	rep(i,N) cin>>a[i],a[i]--;
	int ans = 0;
	rep(i,N){
		int v = a[i];
		if(now.count(v)) continue;
		ans++;
		if(now.size()==K){
			int dis = -1, mx = -1;
			for(int u:now){
				int nxt = N;
				for(int j=i+1;j<N;j++){
					if(a[j]==u){
						nxt = j;
						break;
					}
				}
				if(mx<nxt){
					mx = nxt;
					dis = u;
				}
			}
			now.erase(dis);
		}
		now.insert(v);
	}
	cout<<ans<<endl;
}