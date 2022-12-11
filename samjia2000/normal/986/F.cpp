#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int L = 32e6;
const int C = 1e4+5;
const int N = 1e5+5;
const LL INF = 1e12;

int P[3000005],u;
bool bz[L+5];

void prepare(){
	fo(i,2,L){
		if (!bz[i])P[++u]=i;
		fo(j,1,u){
			if (1ll*i*P[j]>L)break;
			bz[i*P[j]]=1;
			if (i%P[j]==0)break;
		}
	}
}

bool ans[C];
struct query{
	LL n,k;
	int id;
}qry[C];

bool cmp(query a,query b){return a.k<b.k;}

LL pri[C];
int m;

LL dis[N];

LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}

struct status{
	int x;
	LL dis;
	status(const int x_=0,const LL dis_=0){x=x_;dis=dis_;}
	friend bool operator <(status a,status b){return a.dis!=b.dis?a.dis<b.dis:a.x<b.x;}
};
set<status>s;

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

void solve(int L,int R){
	LL k=qry[L].k;
	if (k==1)return;
	m=0;
	int lim=sqrt(k);
	fo(i,1,u){
		if (1ll*P[i]*P[i]>k)break;
		if (k%P[i]==0){
			pri[++m]=P[i];
			while(k%P[i]==0)k/=P[i];
		}
	}
	if (k>1)pri[++m]=k;
	if (m==1){
		fo(i,L,R)ans[qry[i].id]=(qry[i].n%pri[1]==0);
		return;
	}
	if (m==2){
		fo(i,L,R){
			LL tmp=qry[i].n%pri[1]*quickmi(pri[2]%pri[1],pri[1]-2,pri[1])%pri[1];
			ans[qry[i].id]=(qry[i].n>=tmp*pri[2]);
		}
		return;
	}
	int mo=pri[1];
	fo(i,0,mo-1)dis[i]=-1;
	dis[0]=0;
	s.clear();
	s.insert(status(0,0));
	while(s.begin()!=s.end()){
		int x=(*s.begin()).x;
		s.erase(s.begin());
		fo(i,1,m){
			int y=(x+pri[i])%mo;
			if (dis[y]==-1||dis[y]>dis[x]+pri[i]){
				if (dis[y]!=-1)s.erase(status(y,dis[y]));
				dis[y]=dis[x]+pri[i];
				s.insert(status(y,dis[y]));
			}
		}
	}
	fo(i,L,R){
		if(dis[qry[i].n%mo]==-1)ans[qry[i].id]=0;
		else ans[qry[i].id]=(qry[i].n>=dis[qry[i].n%mo]);
	}
}

int main(){
	prepare();
	int T=get();
	fo(i,1,T){
		qry[i].id=i;
		scanf("%I64d%I64d",&qry[i].n,&qry[i].k);
	}
	sort(qry+1,qry+1+T,cmp);
	int lst=0;
	fo(i,1,T){
		if (i==T||qry[i].k!=qry[i+1].k){
			solve(lst+1,i);
			lst=i;
		}
	}
	fo(i,1,T)
	if (ans[i])printf("YES\n");
	else printf("NO\n");
	return 0;
}