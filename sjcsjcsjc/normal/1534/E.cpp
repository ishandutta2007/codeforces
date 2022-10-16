#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,k,dist[510],pre[510];
vector<int> v; 

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<=n;i++) dist[i]=INF;
	dist[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=0;i<=k;i++) if(i<=t&&k-i<=n-t){
			int nxt=t-i+(k-i);
			if(dist[nxt]>dist[t]+1){
				dist[nxt]=dist[t]+1;
				pre[nxt]=t;
				q.push(nxt);
			}
		}
	}
	if(dist[0]==INF){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> v;
	int now=0;
	while(now!=n){
		v.push_back(now);
		now=pre[now];
	}
	vector<int> v1,v2;
	for(int i=1;i<=n;i++) v1.push_back(i);
	int ans=0,cur=n;
	for(int i=v.size()-1;i>=0;i--){
		int val1=(k+cur-v[i])/2,val2=(k-cur+v[i])/2;
		cout<<"? ";
		for(int j=0;j<val1;j++) cout<<v1[j]<<" ";
		for(int j=0;j<val2;j++) cout<<v2[j]<<" ";
		cout<<'\n';
		fflush(stdout);
		int x;cin>>x;ans^=x; 
		vector<int> nw1,nw2;
		for(int j=val1;j<v1.size();j++) nw1.push_back(v1[j]);
		for(int j=0;j<val2;j++) nw1.push_back(v2[j]);
		for(int j=0;j<val1;j++) nw2.push_back(v1[j]);
		for(int j=val2;j<v2.size();j++) nw2.push_back(v2[j]);
		v1=nw1;v2=nw2;cur=v[i];
	}
	cout<<"! "<<ans<<'\n';
	fflush(stdout);
	return 0;
}