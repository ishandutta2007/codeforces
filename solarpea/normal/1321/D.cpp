//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read();
int dist[200005],a[200005],cnt[200005];
vector<int> g[200005],rg[200005];
signed main(){
	fz(i,1,m){
		int u=read(),v=read();
		g[u].push_back(v);
		rg[v].push_back(u); 
	}
	int p=read();
	fz(i,1,p){
		a[i]=read();
	}
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0,a[p]});
	fillbig(dist);dist[a[p]]=0;
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int sum=p.fi,x=p.se;
		foreach(it,rg[x]){
			int y=*it;
			if(dist[y]>dist[x]+1){
				dist[y]=dist[x]+1;
				pq.push({dist[y],y});
			}
		}
	}
//	fz(i,1,n)	cout<<dist[i]<<endl;
	int ans1=0,ans2=0;
	fz(i,1,n){
		foreach(it,g[i]){
			int j=*it;
			if(dist[j]+1==dist[i])	cnt[i]++;
		}
//		cout<<cnt[i]<<endl;
	}
	fz(i,1,p-1){
		if(dist[a[i]]!=dist[a[i+1]]+1){
			ans1++;ans2++;
			continue;
		}
		if(cnt[a[i]]>1)	ans2++;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}