#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,cnt,p1[200010],p2[200010];
set<int> v[200010];
bool vis[200010];
set<int> s;

inline int find_set(int x,int p[])
{
	return p[x]==x?x:p[x]=find_set(p[x],p);
}

inline bool unite(int x,int y,int p[])
{
	int rootx=find_set(x,p),rooty=find_set(y,p);
	if(rootx==rooty) return false;
	p[rooty]=rootx;return true;
}

inline bool check(int x,int y,int p[])
{
	int rootx=find_set(x,p),rooty=find_set(y,p);
	if(rootx==rooty) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<pair<int,pair<int,int> > > e;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x,y,c;cin>>x>>y>>c;ans^=c; 
		e.push_back(make_pair(c,make_pair(x,y)));
		v[x].insert(y);v[y].insert(x);
	}
	int tot=n*(n-1)/2-m;
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++) s.insert(i);
	for(int i=1;i<=n;i++) p1[i]=i;
	for(int i=1;i<=n;i++) if(!vis[i]){
		s.erase(s.find(i));cnt++;
		queue<int> q;q.push(i);
		while(!q.empty()){
			int t=q.front();q.pop();vis[t]=1;
			for(set<int>::iterator it=s.begin();it!=s.end();){
				int now=(*it);it++;
				if(v[t].find(now)==v[t].end()){
					q.push(now);s.erase(s.find(now));
					unite(t,now,p1);
				}
			}
		}
	}
	int res=0,minv=0;
	if(tot==n-cnt) minv=ans;
	for(int i=1;i<=n;i++) p2[i]=i;
	for(int i=0;i<e.size();i++){
		int x=e[i].second.first,y=e[i].second.second,c=e[i].first;
		if(unite(x,y,p1)){
			res+=c;unite(x,y,p2);
		}
		else{
			if(check(x,y,p2)) minv=min(minv,c);
		}
	}
	cout<<res+minv<<endl;
	return 0;
}