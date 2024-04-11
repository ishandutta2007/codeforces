#include <bits/stdc++.h>
using namespace std;
#define Maxn 400000
#define Inf (1<<30)
int n,a[Maxn+5],i,j,q,sx,sy,tx,ty,ans[Maxn+5];
int f[20][Maxn+5],lo[Maxn+5],st[Maxn+5],w;
int getmin(int x,int y){
	if(x>y){
		swap(x,y);
	}
	int l=lo[y-x+1];
	return min(f[l][x],f[l][y-(1<<l)+1]);
}
struct Node{
	int p,q,k,w,*v;
	int F(const int&i){
		return k*i+(a[i]>q)+abs(p-a[i]);
	}
	void upd(const int&i){
		*v=min(*v,F(i)+w);
	}
};
vector<Node> qu[Maxn+5][2];
int G(const int&x){
	return x<0?-x:a[x];
}
bool cmp(const int&x,const int&y){
	return G(x)<G(y);
}
void work(Node&u,int o){
	int l=1,r=u.q>Inf?lower_bound(st+1,st+w+1,Inf-u.q,cmp)-st:w,m1,m2,dt;
	if(u.q>Inf){
		l=r,r=w;
	}
	for(;r-l>9;){
		dt=(r-l)/3;
		m1=l+dt;
		m2=r-dt;
		if(u.F(st[m1])>u.F(st[m2])){
			l=m1;
		}
		else{
			r=m2;
		}
	}
	for(;l<=r;l++){
		u.upd(st[l]);
	}
}
void solve(int o){
	int i=o==0?1:n;
	w=0;
	for(;i>=1&&i<=n;i+=o==0?1:-1){
		for(;w&&a[st[w]]>=a[i];w--);
		st[++w]=i;
		for(auto u:qu[i][o]){
			work(u,o);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	for(i=2;i<=Maxn;i++){
		lo[i]=lo[i>>1]+1;
	}
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i],f[0][i]=a[i];
	}
	for(int i=1;i<=lo[n];i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
	for(cin>>q,j=1;j<=q;j++){
		int ff;
		ans[j]=Inf;
		cin>>sx>>sy>>tx>>ty;
		ff=min(getmin(sx,tx),sy);
		ans[j]=abs(sx-tx)+min(min(ty+1,a[tx]-ty+1),abs(ty-ff));
		if(sx>=tx){
			ff=getmin(sx,tx);
			if(ff>=ty){
				qu[sx+1][1].push_back((Node){ty,sy,2,-tx-sx,ans+j});
			}
			qu[tx][1].push_back((Node){ty,Inf+ff,0,abs(sx-tx)+1,ans+j});
			ff=min(getmin(sx,tx),sy);
			qu[tx][0].push_back((Node){ty,ff,-2,tx+sx,ans+j});
		}
		if(sx<=tx){
			ff=getmin(sx,tx);
			if(ff>=ty){
				qu[sx-1][0].push_back((Node){ty,sy,-2,tx+sx,ans+j});
			}
			qu[tx][0].push_back((Node){ty,Inf+ff,0,abs(sx-tx)+1,ans+j});
			ff=min(getmin(sx,tx),sy);
			qu[tx][1].push_back((Node){ty,ff,2,-tx-sx,ans+j});
		}
	}
	solve(0);
	solve(1);
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}