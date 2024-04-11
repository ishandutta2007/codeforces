#include <bits/stdc++.h>
using namespace std;

mt19937 Rand(998244353);
int cnt,root,sz[400010],l[400010],r[400010],rnd[400010],val[400010],u[400010],minv[400010],tag[400010];
int a[400010],pre[400010],k[400010];
long long sum[400010];

inline void update(int x)
{
	sz[x]=sz[l[x]]+sz[r[x]]+1;
	minv[x]=u[x];
	if(l[x]) minv[x]=min(minv[x],minv[l[x]]);
	if(r[x]) minv[x]=min(minv[x],minv[r[x]]);
}

inline void pushdown(int x)
{
	if(tag[x]){
		if(l[x]){
			minv[l[x]]+=tag[x];u[l[x]]+=tag[x];tag[l[x]]+=tag[x];
		}
		if(r[x]){
			minv[r[x]]+=tag[x];u[r[x]]+=tag[x];tag[r[x]]+=tag[x];
		}
		tag[x]=0;
	}
}

inline int newnode(int x,int y)
{
	cnt++;
	l[cnt]=0;
	r[cnt]=0;
	sz[cnt]=1;
	rnd[cnt]=Rand();
	val[cnt]=x;
	u[cnt]=y;
	minv[cnt]=y;
	tag[cnt]=0;
	return cnt;
}

inline int merge(int a,int b)
{
	if(!a||!b) return a+b;
	if(rnd[a]<rnd[b]){
		pushdown(a);
		r[a]=merge(r[a],b);
		update(a);
		return a;
	}
	else{
		pushdown(b);
		l[b]=merge(a,l[b]);
		update(b);
		return b;
	}
}

inline void split(int node,int k,int &a,int &b)
{
	if(!node){
		a=0;b=0;
	}
	else{
		pushdown(node);
		if(val[node]<=k){
			a=node;
			split(r[node],k,r[node],b);
		}
		else{
			b=node;
			split(l[node],k,a,l[node]);
		}
		update(node);
	}
}

inline void split2(int node,int num,int &a,int &b)
{
	if(!node){
		a=0;b=0;
	}
	else{
		pushdown(node); 
		if(num<=sz[l[node]]){
			b=node;
			split2(l[node],num,a,l[node]);
		}
		else{
			a=node;
			split2(r[node],num-sz[l[node]]-1,r[node],b);
		}
		update(node);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		vector<vector<int> > v;v.resize(m+1); 
		for(int i=1;i<=m;i++) sum[i]=0ll;
		for(int i=1;i<=m;i++){
			cin>>k[i];v[i].resize(k[i]+1);
			for(int j=1;j<=k[i];j++) cin>>v[i][j],sum[i]+=1ll*v[i][j];
			int x=sum[i]/k[i]+(sum[i]%k[i]!=0);
			pre[i]=n+1-(lower_bound(a+1,a+n+1,x)-a);
		}
		cnt=0;root=0;
		for(int i=1;i<=m;i++){
			int A,B;
			split(root,pre[i],A,B);
			if(B){
				minv[B]--;u[B]--;tag[B]--;
			}
			root=merge(merge(A,newnode(pre[i],pre[i]-sz[A]-1)),B);
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				sum[i]-=1ll*v[i][j];k[i]--;
				int x=sum[i]/k[i]+(sum[i]%k[i]!=0);
				int A,B,C;
				split(root,pre[i]-1,A,B);
				split2(B,1,C,B);
				if(B){
					minv[B]++;u[B]++;tag[B]++;
				}
				root=merge(A,B);
				pre[i]=n+1-(lower_bound(a+1,a+n+1,x)-a);
				split(root,pre[i],A,B);
				if(B){
					minv[B]--;u[B]--;tag[B]--;
				}
				root=merge(merge(A,newnode(pre[i],pre[i]-sz[A]-1)),B);
				if(minv[root]>=0) cout<<1;
				else cout<<0;
				sum[i]+=1ll*v[i][j];k[i]++;
			}
			int x=sum[i]/k[i]+(sum[i]%k[i]!=0);
			int A,B,C;
			split(root,pre[i]-1,A,B);
			split2(B,1,C,B);
			if(B){
				minv[B]++;u[B]++;tag[B]++;
			}
			root=merge(A,B);
			pre[i]=n+1-(lower_bound(a+1,a+n+1,x)-a);
			split(root,pre[i],A,B);
			if(B){
				minv[B]--;u[B]--;tag[B]--;
			}
			root=merge(merge(A,newnode(pre[i],pre[i]-sz[A]-1)),B);
		}
		cout<<'\n';
	}
	return 0;
}