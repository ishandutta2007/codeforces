#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
const int B=250;
char str[100010];
int Q;
char t[100010];
struct SAM{
	int l,r;
	int tr[710][26],fa[710],sum[710],mxl[710];
	vector<int>vec[710];
	int lst=1,cnt=1;
	void insert(int x){
		int nw=++cnt;mxl[nw]=mxl[lst]+1;sum[nw]=1;
		int p=lst;lst=cnt;
		while(p&&!tr[p][x]) tr[p][x]=nw,p=fa[p];
		if(!p){
			fa[nw]=1;return ;
		}
		int q=tr[p][x];
		if(mxl[q]==mxl[p]+1){
			fa[nw]=q;
		}
		else{
			++cnt;fa[cnt]=fa[q];for(int i=0;i<26;++i) tr[cnt][i]=tr[q][i];fa[q]=fa[nw]=cnt;
			mxl[cnt]=mxl[p]+1;
			while(p&&tr[p][x]==q) tr[p][x]=cnt,p=fa[p];
		}
	}
	void dfs(int x){
		for(int v:vec[x]){
			dfs(v);sum[x]+=sum[v];
		}
	}
	int check(int x){
		int nw=0,p=1;
		for(int i=1;i<=x;++i){
			p=tr[p][t[i]-'a'];if(!p) return 0;
		}
		return sum[p];
	}
	void clear(){
		for(int i=1;i<=cnt;++i) vector<int>().swap(vec[i]);
		for(int i=1;i<=cnt;++i) for(int j=0;j<26;++j) tr[i][j]=fa[i]=sum[i]=mxl[i]=0;
		lst=cnt=1;
	}
}bl[540];
void rebuild(int x){
	bl[x].clear();
	for(int j=bl[x].l;j<=bl[x].r;++j) bl[x].insert(str[j]-'a');
	for(int i=2;i<=bl[x].cnt;++i) bl[x].vec[bl[x].fa[i]].pb(i);
	bl[x].dfs(1);
}
int bel[100010];
const int m1=998244353,m2=1e9+7;
const int d1=31,d2=37;
int p1[100010],p2[100010];
struct has{
	int h1,h2;
	void clear(){
		h1=h2=0;
	}
	has(long long x,long long y){
		h1=x,h2=y;
	}
	has(){
		h1=h2=0;
	}
	friend bool operator ==(has x,has y){return x.h1==y.h1&&x.h2==y.h2;}
}hsh[100010];
has ge(int l,int r){
	return has{(hsh[r].h1-1ll*hsh[l-1].h1*p1[r-l+1]%m1+m1)%m1,(hsh[r].h2-1ll*hsh[l-1].h2*p2[r-l+1]%m2+m2)%m2};
}
has tr(has x,int k){
	return has{(1ll*x.h1*d1+k)%m1,(1ll*x.h2*d2+k)%m2};
}
int bruteforce(int l,int r,int m){
	// printf("l:%d,r:%d,m:%d\n",l,r,m);
	hsh[l-1].clear();
	for(int i=l;i<=r;++i) hsh[i]=tr(hsh[i-1],str[i]-'a');
	has h;h.clear();
	for(int i=1;i<=m;++i) h=tr(h,t[i]-'a');
	int ret=0;
	for(int i=l+m-1;i<=r;++i) ret+=(ge(i-m+1,i)==h);return ret;
}
int cnt,n;
int main(){
	p1[0]=p2[0]=1;
	for(int i=1;i<=100000;++i) p1[i]=1ll*p1[i-1]*d1%m1,p2[i]=1ll*p2[i-1]*d2%m2;
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i+=B){
		++cnt;for(int j=0;j<B&&i+j<=n;++j) bel[i+j]=cnt,bl[cnt].insert(str[i+j]-'a'),bl[cnt].r=i+j;bl[cnt].l=i;rebuild(cnt);
		// printf("%d %d\n",bl[cnt].l,bl[cnt].r);
	}
	Q=read();
	while(Q--){
		int op=read();
		if(op==1){
			int l=read();char c=getchar();while(c<'a'||c>'z') c=getchar();
			str[l]=c;rebuild(bel[l]);
		}
		else{
			int l=read(),r=read();scanf("%s",t+1);
			int m=strlen(t+1);
			int ans=0;
			if(m>B){
				ans+=bruteforce(l,r,m);
			}
			else if(bel[l]==bel[r]){
				ans+=bruteforce(l,r,m);
			}
			else {
				for(int j=bel[l]+1;j<bel[r];++j){
					// printf("j:%d,%d\n",j,bl[j].check(m));
					ans+=bl[j].check(m);
				}
				ans+=bruteforce(l,bl[bel[l]].r,m);
				ans+=bruteforce(bl[bel[r]].l,r,m);
				for(int j=bel[l]+1;j<=bel[r];++j){
					if(m) ans+=bruteforce(max(l,bl[j-1].r-m+2),min(r,bl[j].l+m-2),m);
				}
			}
			printf("%d\n",ans);
		}
	}
}