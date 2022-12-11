#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;
typedef unsigned int ui;
typedef unsigned long long ull;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int Lim = 22;
const int N = 1e6+5;

struct Vector{
	int a[30],len;
	int &operator [](int x){return a[x];}
}Now,st[N];
int val[N];
int k;
int key[N],n;
int dis[300][2005];
map<ull,int>id;

void dfs(int x,int sum,int pre){
	k++;
	st[k].len=x-1;
	fo(i,1,x-1)st[k][i]=Now[i];
	ull t=0;
	fo(i,1,x-1)t=t*97+Now[i];
	id[t]=k;
	val[k]=1;
	fo(i,1,x-1)val[k]*=Now[i]+1;
	fo(i,pre,Lim-sum){
		Now[x]=i;
		dfs(x+1,sum+i,i);
	}
}

int lst[N],pri[N],m;
bool bz[N];
int pt[N],u;

struct edge{
	int x,nxt;
}e[N];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int que[N],Dis[N];
int Id[N],ins[N];
int cv[N];
int ans[300][300];

void prepare(){
	dfs(1,0,1);
	m=0;
	fo(i,2,1e6){
		if (!lst[i])pri[++m]=lst[i]=i;
		fo(j,1,m){
			if (1ll*i*pri[j]>1e6)break;
			lst[i*pri[j]]=pri[j];
			if (i%pri[j]==0)break;
		}
	}
	lst[1]=1;
	fo(i,1,1e6){
		u=0;
		cv[i]=1;
		for(int x=i;x>1;){
			int v=lst[x];
			pt[++u]=0;
			for(;x%v==0;x/=v,pt[u]++);
			cv[i]*=pt[u]+1;
		}
		sort(pt+1,pt+1+u);
		ull t=0;
		fo(x,1,u)t=t*97+pt[x];
		bz[ins[i]=id[t]]=1;
	}
	n=0;
	fo(i,1,k)if (bz[i])key[Id[i]=++n]=i;
	fo(i,1,k){
		Vector tmp=st[i];
		fo(x,1,st[i].len)
			fo(c,0,1){
				tmp[x]+=c*2-1;
				sort(tmp.a+1,tmp.a+1+st[i].len);
				ull t=0;
				if (tmp[1])fo(w,1,st[i].len)t=t*97+tmp[w];
				else fo(w,2,st[i].len)t=t*97+tmp[w];
				if (id[t])inse(i,id[t]);
				tmp=st[i];
			}
		tmp[st[i].len+1]=1;
		sort(tmp.a+1,tmp.a+2+st[i].len);
		ull t=0;
		fo(w,1,st[i].len+1)t=t*97+tmp[w];
		if (id[t])inse(i,id[t]);
	}
	fo(w,1,n){
		int St=key[w];
		fo(i,1,k)Dis[i]=-1;
		Dis[St]=0;
		int he=0,ta=1;
		que[1]=St;
		for(;he<ta;){
			int x=que[++he];
			for(int p=h[x];p;p=e[p].nxt)
			if (Dis[e[p].x]==-1){
				Dis[e[p].x]=Dis[x]+1;
				que[++ta]=e[p].x;
			}
		}
		fo(i,1,2000)dis[w][i]=1e9;
		fo(i,1,k)
		if (Dis[i]!=-1&&val[i]<=2000)dis[w][val[i]]=min(dis[w][val[i]],Dis[i]);
	}
	fo(i,1,n)
		fo(j,1,n){
			ans[i][j]=1e9;
			fo(x,1,2000)
			if (dis[i][x]!=-1&&dis[j][x]!=-1)ans[i][j]=min(ans[i][j],dis[i][x]+dis[j][x]);
		}
}

int main(){
	prepare();
	for(int T=get();T;T--){
		int a=get(),b=get();
		a=Id[ins[a]];
		b=Id[ins[b]];
		printf("%d\n",ans[a][b]);
	}
	return 0;
}