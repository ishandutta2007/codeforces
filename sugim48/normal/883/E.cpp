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
int N,M;
string s;
string ts[1000];
bool already[26];
bool ans[26];
int main(){
	rep(i,26) ans[i] = 1;
	cin>>N;
	cin>>s;
	cin>>M;
	rep(i,M) cin>>ts[i];
	rep(i,N) if(s[i]!='*') already[s[i]-'a'] = 1;

	rep(j,M){
		string t = ts[j];
		bool can = 1;
		rep(i,N){
			if(s[i]=='*'){
				if(already[t[i]-'a']) can = 0;
			}else{
				if(s[i]!=t[i]) can = 0;
			}
		}
		if(!can) continue;
		if(can){
			bool has[26]={};
			rep(i,N) has[t[i]-'a'] = 1;
			rep(i,26) if(!has[i]) ans[i] = 0;
		}
	}
	int res = 0;
	rep(i,26) if(!already[i] && ans[i]) res++;
	cout<<res<<endl;
}