#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=100100;
int n;
nagai p;
struct ev{
	nagai time;
	int type;
	int id;
	bool operator <(ev b)const{
		return tie(time,type,id)<tie(b.time,b.type,b.id);
	}
};
nagai ans[N];
bool qcount[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	deque<int>q;
	set<ev>st;
	for(int i=0;i<n;++i){
		int t;
		cin>>t;
		st.insert({t,0,i});
	}
	set<int>wait;
	while(st.size()){
		auto e=*st.begin();
		st.erase(st.begin());
//		cerr<<e.time<<' '<<e.type<<' '<<e.id<<'\n';
		if(e.type==0){
			if(!wait.size()||*wait.begin()>e.id){
				if(q.empty())
					st.insert({e.time+p,1,e.id});
				q.push_back(e.id);
				qcount[e.id]=true;
			}
			wait.insert(e.id);
		}
		else{
			assert(q.size());
			int x=q.front();
			assert(x==e.id);
			q.pop_front();
			ans[e.id]=e.time;
			wait.erase(e.id);
			if(!q.empty()){
				st.insert({e.time+p,1,q.front()});
			}
			if(wait.size()){
				int x=*wait.begin();
				if(!qcount[x]){
					if(q.empty())
						st.insert({e.time+p,1,x});
					q.push_back(x);
					qcount[x]=true;
				}
			}
		}
	}
	for(int i=0;i<n;++i)
		cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}