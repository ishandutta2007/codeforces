#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		LL s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	LL s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e6+5;
const int L = (1<<11)+5;
const LL INF = 1e18;

int n;
LL a[N];
LL k,g;
int e[N];

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

LL pri[100],pdt[100];
int u;

LL key[N];
int m;

map<LL,int>id;

LL pv[100];
int all[200000][15];
int pos[L][15];

void push(int *a,int x){
	int w=a[0]+1;
	fo(i,1,a[0])if (e[x]<e[a[i]]){w=i;break;}
	fd(i,a[0]+1,w+1)a[i]=a[i-1];
	a[w]=x;
	a[0]=min(a[0]+1,u);
}

LL f[L][15],p[L][15];
int vis[L],tim;
int que[L],ta;

set<int>st[N];

int main(){
//	freopen("data.in","r",stdin);
	n=get();k=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)e[i]=get();
	g=a[1];
	fo(i,2,n)g=gcd(g,a[i]);
	if (g==1)return printf("0\n"),0;
	u=0;
	LL x=g,lim=sqrt(g);
	fo(i,2,lim)
	if (x%i==0){
		pri[++u]=i;
		pdt[u]=1;
		for(;x%i==0;x/=i,pdt[u]*=i);
	}
	if(x>1){
		u++;
		pri[u]=pdt[u]=x;
	}
	fo(i,1,n){
		LL r=a[i],x=1;
		for(LL d=gcd(r,g);d>1;d=gcd(r,g))r/=d,x*=d;
		if(!id[x])key[id[x]=++m]=x;
		push(all[id[x]],i);
	}
	fo(w,1,m){
		LL x=key[w];
		fo(i,1,u){
			pv[i]=1;
			for(;x%pri[i]==0;)x/=pri[i],pv[i]*=pri[i];
		}
		fo(s,0,(1<<u)-1){
			LL v=1;
			fo(i,1,u)
			if ((s&(1<<(i-1)))>0)v*=pv[i];
			if(v<=k){
				fo(x,1,all[w][0])
				push(pos[s],all[w][x]);
			}
		}
	}
	fo(s,0,(1<<u)-1)fo(i,1,pos[s][0])st[pos[s][i]].insert(s);
	fo(s,0,(1<<u)-1)fo(i,0,u)f[s][i]=INF;
	f[0][0]=0;
	fo(x,1,n)
	if(st[x].begin()!=st[x].end()){
		tim++;
		ta=0;
		for(set<int>::iterator h=st[x].begin();h!=st[x].end();h++){
			int s=(*h);
			int res=((1<<u)-1)^s;
			for(int t=0;;t=((t^s)+1)&res){
				if (vis[t^s]<tim){
					vis[que[++ta]=t^s]=tim;
					fo(i,0,u)p[t^s][i]=INF;
				}
				fo(i,0,u-1)
				if (f[t][i]<INF)p[t^s][i+1]=min(p[t^s][i+1],f[t][i]+e[x]);
				if (t==res)break;
			}
		}
		fo(w,1,ta){
			int s=que[w];
			fo(i,0,u)f[s][i]=min(f[s][i],p[s][i]);
		}
	}
	LL ans=INF;
	fo(i,0,u)if (f[(1<<u)-1][i]<INF)ans=min(ans,f[(1<<u)-1][i]*i);
	if (ans==INF)ans=-1;
	cout<<ans<<endl;
	return 0;
}