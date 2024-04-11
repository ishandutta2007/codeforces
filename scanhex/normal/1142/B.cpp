#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
#define next aoeunsth

const int LG=18;
const int N=1<<LG;
int n,m,q;
int p[N];
int a[N];
int next[N];
int last[N];
int ups[LG][N];
int go(int x){
	int kek=n-1;
	for(int i=LG-1;i>=0;--i){
		if(kek>>i&1)
			x=ups[i][x],kek^=1<<i;
		if(x==m)
			return m;
	}
	return x;
}
int t[2*N];
void st(int x,int y){
	 x+=N;
	 t[x]=y;
	 while(x>1)t[x>>1]=min(t[x],t[x^1]),x>>=1;
}
int get(int l,int r){
	 l+=N;
	 r+=N;
	 int ans=m;
	 while(l<r){
		  if(l&1)
			  ans=min(ans,t[l++]);
		  if(r&1)
			  ans=min(ans,t[--r]);
		  l/=2,r/=2;
	 }
	 return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;++i)cin>>p[i],--p[i];
	for(int i=0;i<n;++i)next[p[i]]=p[(i+1)%n];
	for(int j=0;j<m;++j)cin>>a[j],--a[j];
	fill(last,last+n,m);
	for(int i=m-1;i>=0;--i){
		ups[0][i]=last[next[a[i]]];
		last[a[i]]=i;
	}
	for(int i=0;i+1<LG;++i)
		for(int j=0;j<m;++j){
			if(ups[i][j]==m)ups[i+1][j]=m;
			else ups[i+1][j]=ups[i][ups[i][j]];
		}
	for(int i=0;i<m;++i){
		st(i,go(i));
	}
	for(int i=0;i<q;++i){
		 int l,r;
		 cin>>l>>r;
		 --l;
		 int mem=get(l,r);
		 if(mem<r)
			 cout<<1;
		 else
			 cout<<0;
	}
	cout<<'\n';
	return 0;
}