#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int n,m,from,to,conse,idx,mx,ind,x;
int longest2[200005];
pair<int,int> longest1[200005];
vector<int> v[200005];
const int INF=1e9;
queue<int > q;
bool cmp(int r,int v){
	return r<v;
}
int main(){
	cin>>n>>x;
	rep(i,1,n-1){
		cin>>from>>to;
		v[from].pb(to);
		v[to].pb(from);
	}
	memset(longest1,-1,sizeof longest1);
	memset(longest2,-1,sizeof longest2);
	rep(i,1,n)longest1[i].se=i;
	longest1[1].fi=0;
	
	q.push(1);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(v[cur].size()==0)continue;
		rep(i,0,v[cur].size()-1){
			int nx=v[cur][i];
			if(longest1[nx].fi==-1){
				longest1[nx].fi=longest1[cur].fi+1;
				q.push(nx);
			}
		}
	}
	longest2[x]=0;
	q.push(x);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(v[cur].size()==0)continue;
		rep(i,0,v[cur].size()-1){
			int nx=v[cur][i];
			if(longest2[nx]==-1){
				longest2[nx]=longest2[cur]+1;
				q.push(nx);
			}
		}
	}
	sort(longest1+1,longest1+n+1);
	rap(i,n,1){
		//cout<<longest1[i].se<<" ";
		if(longest1[i].fi>longest2[longest1[i].se]){
			cout<<2*longest1[i].fi<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}