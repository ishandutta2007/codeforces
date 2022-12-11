#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;


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

const int N = 3e5+5;
const int B = 550;
const int mo = 984616561;
const int P = 399667;

int T;
int n,q;
int que[N];
struct point{
	int x,nxt;
}pt[N];
int h[N],tot;
int siz[N];

void inse(int x,int y){pt[++tot].x=y;pt[tot].nxt=h[x];h[x]=tot;}

struct addition{
	int pos,nxt;
}ad[N];
int hd[N],td;

void add(int x,int pos){ad[++td].pos=pos;ad[td].nxt=hd[x];hd[x]=td;}

int vis[N],tim;
LL ha[N];

int rk[N];
LL pre[N],mi[N];
LL pv[N],sv[N];

bool solve(){
	n=get();q=get();
	tot=0;
	td=0;
	fo(i,1,n)hd[i]=0;
	fo(i,1,q){
		h[i]=0;
		int k=get();
		siz[i]=k;
		fo(j,1,k)que[j]=get();
		fd(j,k,1){
			inse(i,que[j]);
			if (siz[i]<B)add(que[j],tot);
		}
	}
	fo(i,1,n){
		tim++;
		for(int st=hd[i];st;st=ad[st].nxt){
			int pos=ad[st].pos;
			LL v=0;
			for(int p=pos;p;p=pt[p].nxt){
				int x=pt[p].x;
				v=(v*P+x)%mo;
				if (vis[x]<tim)ha[x]=v,vis[x]=tim;
				if (ha[x]!=v)return 0;
			}
		}
	}
	fo(d,1,q)
	if(siz[d]>=B){
		int k=0;
		for(int p=h[d];p;p=pt[p].nxt)que[++k]=pt[p].x;
		tim++;
		fo(i,1,k){
			int x=que[i];
			vis[x]=tim;
			rk[x]=i;
			pre[i]=(pre[i-1]*P+x)%mo;
		}
		fo(u,d+1,q){
			int lst=0,key=0;
			rk[0]=1e9;
			for(int p=h[u];p;p=pt[p].nxt){
				int x=pt[p].x;
				sv[x]=pv[lst];
				pv[x]=(pv[lst]*P+x)%mo;
				lst=x;
				if (vis[x]<tim)continue;
				if (rk[x]>rk[key]){
					int len=rk[x]-rk[key]+1;
					LL ha1=(pre[rk[x]]+mo-pre[rk[key]-1]*mi[len]%mo)%mo;
					LL ha2=(pv[x]+mo-sv[key]*mi[len]%mo)%mo;
					if (ha1!=ha2)return 0;
				}
				else key=x;
			}
		}
	}
	return 1;
}

int main(){
	mi[0]=1;
	fo(i,1,3e5)mi[i]=mi[i-1]*P%mo;
	for(int T=get();T;T--)printf("%s\n",solve()?"Robot":"Human");
	return 0;
}