#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N],b[N],par[N],dist[N];
vector<int> v[N];
queue<int> q;
pair<int,int> seg[N];

void build(){
	f_(i,n-1,1){
		seg[i]=min(seg[i*2+0],seg[i*2+1]);
		//erorp(seg[i]);	
	}
}
pair<int,int> Get(int l, int r) {
	l--,r--;
	pair<int,int> mn=mp(N,N);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1){
			minm(mn,seg[l++]);
		}
		if (r&1){
			minm(mn,seg[--r]);
		}
	}
	return mn;
}
void change(int x){
	x+=n-1;
	seg[x]=mp(N,N);
	while(x){
		x/=2;
		seg[x]=min(seg[x*2+0],seg[x*2+1]);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(dist,dist+N,N);
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]=i-a[i];
		if(a[i]==0){
			q.push(i);
			dist[i]=0;
			seg[i+n-1]=mp(N,N);
		}
		else seg[i+n-1]=mp(a[i],i);
	}
	build();
	f(i,1,n+1){
		int x;
		cin>>x;
		b[i]=i+x;
		v[i+x].pb(i);
	}
	while(q.size()){
		int u=q.front();
		//cout<<u<<" dist "<<dist[u]<<endl;
		q.pop();
		f(i,0,v[u].size()){
			//eror(v[u][i]);
			pair<int,int> p=Get(v[u][i]+1,n+1);
			while(p.F<=v[u][i]){
				//erorp(p);
				dist[p.S]=dist[u]+1;
				par[p.S]=v[u][i];
				change(p.S);
				q.push(p.S);
				p=Get(v[u][i]+1,n+1);
			}
		}
	}
	if(dist[n]==N) return cout<<-1,0;
	cout<<dist[n]+1<<endl;
	int u=n;
	while(u!=0){
		u=par[u];
		cout<<u<<" ";
		u=b[u];
	}
}