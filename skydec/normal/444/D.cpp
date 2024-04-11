#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=61000;
vector<int>pos[N*10];
vector<pii>ask[N*10];
char a[N];int n,q;char b[6];int x[N*2],y[N*2];
int ans[N*2];char t[6];bool yd[N*2];
int S=405;
int shao[N*10],duo[N*10];
inline void minit(int &a,const int &b){if(b<a)a=b;}
int len[N*10];int tt[N*2];bool is[N*2];
inline int work(int xx,int yy){
	int rp=23333333;
	int n1,n2;n1=n2=0;
	int le=pos[xx].size()+pos[yy].size();
	rep(i,1,le)if(n1==pos[xx].size()){tt[i]=pos[yy][n2];n2++;is[i]=0;}
	else if(n2==pos[yy].size()){tt[i]=pos[xx][n1];n1++;is[i]=1;}
	else if(pos[xx][n1]<pos[yy][n2]){tt[i]=pos[xx][n1];n1++;is[i]=1;}
	else {tt[i]=pos[yy][n2];n2++;is[i]=0;}
	
	int jin=-233333333;
	rep(i,1,le)if(is[i])jin=tt[i]-len[xx]+1;
	else minit(rp,tt[i]-jin+1);
	
	jin=23333333;
	per(i,le,1)if(is[i])jin=tt[i];
	else minit(rp,jin-(tt[i]-len[yy]+1)+1);
	
	return rp;
}
int rp[N*10];bool shi[N*10];pii f[N*10];int top;
int main(){
	scanf("%s",a+1);n=strlen(a+1);memset(ans,63,sizeof ans);
	rep(i,0,26)len[i]=1;
	rep(i,27,27*27-1)len[i]=2;
	rep(i,27*27,27*27*27-1)len[i]=3;
	rep(i,27*27*27,27*27*27*27-1)len[i]=4;
	rep(i,1,n)rep(j,i-3,i)if(j>0){
		int bo=0;rep(k,j,i){bo*=27;bo+=a[k]-'a'+1;}
		pos[bo].pb(i);
	}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%s",b+1);int m=strlen(b+1);rep(j,1,m){x[i]*=27;x[i]+=b[j]-'a'+1;}rep(j,1,m)t[j]=b[j];int m2=m;
		scanf("%s",b+1);m=strlen(b+1);rep(j,1,m){y[i]*=27;y[i]+=b[j]-'a'+1;}
		if(m2>=m){
			rep(j,1,m2-m+1){
				bool fl=1;
				rep(k,j,j+m-1)if(t[k]!=b[k-j+1])fl=0;
				if(fl&&pos[x[i]].size()){ans[i]=m2;yd[i]=1;}
			}
		}
		else{
			rep(j,1,m-m2+1){
				bool fl=1;
				rep(k,j,j+m2-1)if(b[k]!=t[k-j+1])fl=0;
				if(fl&&pos[y[i]].size()){ans[i]=m;yd[i]=1;}
			}
		}
	}
	rep(i,1,q)if(pos[x[i]].size()<=S&&pos[y[i]].size()<=S&&!yd[i]){
		ans[i]=work(x[i],y[i]);
	}
	else if(!yd[i]){
		if(pos[x[i]].size()>S)ask[x[i]].pb(pii(y[i],i));
		else ask[y[i]].pb(pii(x[i],i));
	}
	rep(i,0,27*27*27*27-1)if(pos[i].size()>S){
		rep(j,0,ask[i].size()-1){shi[ask[i][j].fi]=1;rp[ask[i][j].fi]=23333333;}shi[i]=1;
		top=0;
		rep(r,1,n)rep(l,r-3,r)if(l>0){
			int bo=0;rep(k,l,r){bo*=27;bo+=a[k]-'a'+1;}
			if(!shi[bo])continue;
			f[++top]=pii(r,bo);
		}
		
		int jin=-23333333;
		rep(j,1,top)if(f[j].se==i)jin=f[j].fi-len[i]+1;
		else minit(rp[f[j].se],f[j].fi-jin+1);
		
		jin=233333333;
		per(j,top,1)if(f[j].se==i)jin=f[j].fi;
		else minit(rp[f[j].se],jin-(f[j].fi-len[f[j].se]+1)+1);
		
		rep(j,0,ask[i].size()-1){
			minit(ans[ask[i][j].se],rp[ask[i][j].fi]);
			shi[ask[i][j].fi]=0;
		}
	}
	rep(i,1,q)if(ans[i]>n)printf("-1\n");
	else printf("%d\n",ans[i]);
	return 0;
}