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
int main(){
	int N;
	cin>>N;
	set<string> st;
	rep(qt,N){
		string s;
		cin>>s;
		string t;
		int L = s.size();
		rep(i,L){
			if(s[i]=='u'){
				t = t+"oo";
				continue;
			}else if(s[i]=='k'){
				int k = i;
				while(s[k]=='k') k++;
				if(k<L && s[k]=='h'){
					t = t+"h";
					i = k;
					continue;
				}
			}
			t += s[i];
		}
		st.insert(t);
	}
	cout<<st.size()<<endl;
}