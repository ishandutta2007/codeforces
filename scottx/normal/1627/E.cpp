#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<class T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

#define N 100005
#define inf ((long long)1e18)

vector<int>tmp[N];
vector<ll>dis[N];
vector<vector<array<int,3>>>fuck[N];

int a[N],_a[N],_b[N],_c[N],_d[N],_h[N];
int n,m,K;

void Solve(){
	n=read(),m=read(),K=read();
	
	rep(i,1,n){
		tmp[i].clear(),tmp[i].shrink_to_fit();
		dis[i].clear(),dis[i].shrink_to_fit();
		fuck[i].clear(),fuck[i].shrink_to_fit();
	}
	
	rep(i,1,n)a[i]=read();
	tmp[1].pb(1),tmp[n].pb(m);
	rep(i,1,K){
		_a[i]=read(),_b[i]=read(),_c[i]=read(),_d[i]=read(),_h[i]=read();
		tmp[_a[i]].pb(_b[i]);
		tmp[_c[i]].pb(_d[i]);
	}
	rep(i,1,n){
		sort(tmp[i].begin(),tmp[i].end());
		tmp[i].erase(unique(tmp[i].begin(),tmp[i].end()),tmp[i].end());
		dis[i].assign(SZ(tmp[i]),inf);
		fuck[i].resize(SZ(tmp[i]));
	}
	
	rep(i,1,K){
		int k1=lower_bound(tmp[_a[i]].begin(),tmp[_a[i]].end(),_b[i])-tmp[_a[i]].begin();
		int k2=lower_bound(tmp[_c[i]].begin(),tmp[_c[i]].end(),_d[i])-tmp[_c[i]].begin();
		fuck[_c[i]][k2].pb({_a[i],k1,-_h[i]});
	}
	
	dis[1][0]=0;
	rep(i,1,n){
		rep(j,0,SZ(dis[i])-1){
			for(auto it:fuck[i][j]){
				ckmin(dis[i][j],dis[it[0]][it[1]]+it[2]);
			}
		}
		ll mn=1e18;
		rep(j,0,SZ(dis[i])-1){
			if(j)mn+=1ll*(tmp[i][j]-tmp[i][j-1])*a[i];
			ckmin(dis[i][j],mn);
			ckmin(mn,dis[i][j]);
		}
		mn=1e18;
		per(j,SZ(dis[i])-1,0){
			if(j!=SZ(dis[i])-1)mn+=1ll*(tmp[i][j+1]-tmp[i][j])*a[i];
			ckmin(dis[i][j],mn);
			ckmin(mn,dis[i][j]);
		}
		
//		rep(j,0,SZ(dis[i])-1){
//			printf("dis[%d][%d] = %d\n",i,tmp[i][j],dis[i][j]);
//		}
	}
	if(dis[n].back()>1e17){
		puts("NO ESCAPE");
	}else{
		print(dis[n].back(),'\n');
	}
}

int main(){
	int T=read();
	while(T--){
		Solve();
	}
	return 0;
}