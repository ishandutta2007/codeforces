#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e5+99;

int n,m,t,a[N],L[N],R[N],col[N],vis[N];
vector<int> vec,emp;
queue<int> q;

struct Seg{
	vector<vector<int>> seg1,seg2;
	Seg(){
		f(i,0,m<<1) seg1.pb(emp),seg2.pb(emp); 
	}
	void addp(int x,int id){
		x+=m;
		while(x){
			seg2[x].pb(id);
			x>>=1;
		}
	}
	void addseg(int l,int r,int id){
		for(l+=m,r+=m;l<r;l>>=1,r>>=1){
			if(l&1) seg1[l++].pb(id);
			if(r&1) seg1[--r].pb(id);
		}
	}
	void add(int l,int r,int id){
		addp(l,id);
		addp(r-1,id);
		addseg(l,r,id);
	}
	void getseg(int l,int r){
		for(l+=m,r+=m;l<r;l>>=1,r>>=1){
			if(l&1){
				for(auto x : seg2[l]){
					if(vis[x]==0){
						q.push(x);
						vis[x]=1;
					}
				}
				seg2[l].clear();
				l++;
			}
			if(r&1){
				r--;
				for(auto x : seg2[r]){
					if(vis[x]==0){
						q.push(x);
						vis[x]=1;
					}
				}
				seg2[r].clear();
			}
		}
	}
	void getp(int id){
		id+=m;
		while(id>0){
			for(auto x : seg1[id]){
				if(vis[x]==0){
					q.push(x);
					vis[x]=1;
				}
			}
			seg1[id].clear();
			id>>=1;
		}
	}
	void get(int l,int r){
		getseg(l,r);
		getp(l);
		getp(r-1);
	}
};

void Main(){
	cin>>n;
	f(i,0,n){
		cin>>col[i]>>L[i]>>R[i]; R[i]++;
		vec.pb(L[i]);
		vec.pb(R[i]);
	}
	sort(all(vec));
	f(i,0,n){
		L[i]=lower_bound(all(vec),L[i])-vec.begin();
		R[i]=lower_bound(all(vec),R[i])-vec.begin();
	}
	m=vec.size();
	Seg p0,p1;
	f(i,0,n){
		if(col[i]==0){
			p0.add(L[i],R[i],i);
		}
		else{
			p1.add(L[i],R[i],i);
		}
	}
	int ans=0;
	f(i,0,n){
		if(vis[i]) continue ;
		vis[i]=1;
		q.push(i);
		while(q.size()){
			int id=q.front();
			//cout<<id<<" ";
			q.pop();
			if(col[id]==0){
				p1.get(L[id],R[id]);
			}
			else{
				p0.get(L[id],R[id]);
			}
		}		
		//cout<<endl;
		ans++;
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		vec.clear();
		f(i,0,n) vis[i]=0;
	}
}
/*
1
5
0 0 5
0 4 7
0 13 19
1 2 12
1 9 16

1
3
1 0 1
1 1 2
0 3 4
*/