#include <bits/stdc++.h>
using namespace std;
//Coded in Dongge Jifang 2
//IP address: 192.168.10.106

const int Inf=0x7f7f7f7f;
vector<int> g[200005],c[200005];

struct Event{
	int y,x;
	bool tp;
	int id;
	Event(){}
	Event(int y,int x,bool tp,int id):y(y),x(x),tp(tp),id(id){}
	bool operator<(const Event &e)const{
		if(x!=e.x){
			return x<e.x;
		}else if(tp!=e.tp){
			return tp<e.tp;
		}else{
			return id<e.id;
		}
	}
};

vector<Event> ev;

int l[200005],r[200005],n,t;

int get(int a,int b){
	return min(r[a],r[b])-max(l[a],l[b]);
}

int ans[200005];

int dfs(int v){
	if(ans[v]!=-1){
		return ans[v];
	}
	if(v==1){
		return Inf;
	}
	int &Ans=ans[v];
	Ans=0;
	for(int i=0;i<g[v].size();i++){
		Ans=max(Ans,min(c[v][i],dfs(g[v][i])));
	}
	return Ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	n+=2;
	l[0]=l[1]=-Inf;
	r[0]=r[1]=Inf;
	for(int i=2;i<n;i++){
		int h;
		cin>>h>>l[i]>>r[i];
		ev.push_back(Event(h,l[i],1,i));
		ev.push_back(Event(h,r[i],0,i));
	}
	sort(ev.begin(),ev.end());
	set<pair<int,int> > s;
	s.insert(make_pair(t,0));
	s.insert(make_pair(0,1));
	for(int i=0;i<ev.size();i++){
		if(ev[i].tp==0){
			s.erase(make_pair(ev[i].y,ev[i].id));
		}else{
			set<pair<int,int> >::iterator it=s.insert(make_pair(ev[i].y,ev[i].id)).first;
			set<pair<int,int> >::iterator it2=it;
			it2--;
			int dn=it2->second;
			it2++;
			it2++;
			int up=it2->second;
			if(g[up].size()&&g[up].back()==dn){
				g[up].pop_back();
				c[up].pop_back();
			}
			g[up].push_back(ev[i].id);
			c[up].push_back(get(ev[i].id,up));
			g[ev[i].id].push_back(dn);
			c[ev[i].id].push_back(get(ev[i].id,dn));
		}
	}
	memset(ans,-1,sizeof(ans));
	cout<<dfs(0)<<endl;
	return 0;
}