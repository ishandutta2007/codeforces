#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
namespace MF{
	#define MAXN 252521
	#define MAXM 1919191//2{KvII
	#define wint lint
	const wint wEPS=0;
	const wint wINF=1001001001001001001;
	int n,m,ptr[MAXN],next[MAXM],zu[MAXM];
	int from[MAXM],id[MAXM];
	wint capa[MAXM],tof;
	int lev[MAXN],see[MAXN],que[MAXN],*qb,*qe;
	void init(int _n){
		n=_n;m=0;memset(ptr,~0,n*4);memset(id,-1,sizeof(id));tof=0;
	}
	void ae(int u,int v,wint w0,int Id=-1){
		from[m]=u;id[m]=Id;
		next[m]=ptr[u];ptr[u]=m;zu[m]=v;capa[m]=w0;++m;
		from[m]=v;
		next[m]=ptr[v];ptr[v]=m;zu[m]=u;capa[m]=0;++m;
	}
	wint augment(int src,int ink,wint flo){
		if(src==ink) return flo;
		wint f;
		for(int &i=see[src];~i;i=next[i]) if(capa[i]>wEPS && lev[src]<lev[zu[i]]){
			if((f=augment(zu[i],ink,min(flo,capa[i])))>wEPS){
				capa[i]-=f;capa[i^1]+=f;return f;
			}
		}
		return 0;
	}
	bool solve(int src,int ink,wint flo=wINF){
		wint f;
		int i,u,v;
		for(;tof+wEPS<flo;){
			qb=qe=que;
			memset(lev,~0,n*4);
			for(lev[*qe++=src]=0,see[src]=ptr[src];qb!=qe;){
				for(i=ptr[u=*qb++];~i;i=next[i]) if(capa[i]>wEPS && !~lev[v=zu[i]]){
					lev[*qe++=v]=lev[u]+1;see[v]=ptr[v];
					if(v==ink) goto au;
				}
			}
			return 0;
		au:	for(;(f=augment(src,ink,flo-tof))>wEPS;tof+=f);
		}
		return 1;
	}
}

int x[114514],y[114514],numx[114514],numy[114514],dix[114514],diy[114514];
vector<int> dx,dy;
map<int,int> ex,ey;
int main()
{
	int n,m,t,l,d,r,b,w=0,inf=114514;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&r,&b);
	if(r>b) swap(r,b),w=1;
	rep(i,n){
		scanf("%d %d",&x[i],&y[i]);
		dx.pb(x[i]);dy.pb(y[i]);
	}
	sort(All(dx));dx.erase(unique(All(dx)),dx.end());
	sort(All(dy));dy.erase(unique(All(dy)),dy.end());
	rep(i,dx.size()) ex[dx[i]]=i;rep(i,dy.size()) ey[dy[i]]=i;
	rep(i,n){
		x[i]=ex[x[i]];y[i]=ey[y[i]];
		numx[x[i]]++;numy[y[i]]++;
	}
	int X=dx.size(),Y=dy.size();
	rep(i,X) dix[i]=inf;rep(i,Y) diy[i]=inf;
	
	rep(i,m){
		scanf("%d %d %d",&t,&l,&d);
		if(t==1){
			if(ex.find(l)!=ex.end()) dix[ex[l]]=min(dix[ex[l]],d);
		}
		else{
			if(ey.find(l)!=ey.end()) diy[ey[l]]=min(diy[ey[l]],d);
		}
	}
	
	int S=X+Y,T=S+1,S2=T+1,T2=S2+1;
	lint tmi=0;
	MF::init(X+Y+4);
	rep(i,X){
		if(numx[i]%2>0 && dix[i]==0){cout<<-1<<endl;return 0;}
		int ma=min(numx[i],(numx[i]+dix[i])/2),mi=numx[i]-ma;
		//cerr<<i<<' '<<mi<<' '<<ma<<endl;
		MF::ae(S,i,ma-mi);
		MF::ae(S2,i,mi);
		MF::ae(S,T2,mi);
		tmi+=mi;
	}
	rep(i,Y){
		if(numy[i]%2>0 && diy[i]==0){cout<<-1<<endl;return 0;}
		int ma=min(numy[i],(numy[i]+diy[i])/2),mi=numy[i]-ma;
		//cerr<<i<<' '<<mi<<' '<<ma<<endl;
		MF::ae(X+i,T,ma-mi);
		MF::ae(S2,T,mi);
		MF::ae(X+i,T2,mi);
		tmi+=mi;
	}
	rep(i,n) MF::ae(x[i],X+y[i],1,i);
	//MF::solve(S2,T2);MF::solve(S,T2);MF::solve(S2,T);MF::solve(S,T);
	MF::ae(T,S,1145141919810364364LL);MF::solve(S2,T2);MF::solve(S,T);
	string out(n,'?'),rb="rb";lint tof=0;int num=0;
	rep(i,MF::m){
		if(MF::id[i]>=0){
			out[MF::id[i]]=rb[(MF::capa[i]+w)%2];tof+=1LL-MF::capa[i];num++;
			//cerr<<MF::id[i]<<' '<<MF::capa[i]<<endl;num++;
			if(MF::id[i]>=n || MF::capa[i]<0 || MF::capa[i]>1) cerr<<i<<endl;
		}
		if((MF::from[i]==S2 || MF::zu[i]==T2) && MF::capa[i]>0){cout<<-1<<endl;return 0;}
	}
	//if(r==494247834) cout<<MF::tof-tmi<<' '<<tof<<' '<<MF::tof<<' '<<num<<endl;
	//cout<<(MF::tof-tmi)*r+(n-MF::tof+tmi)*b<<endl;
	cout<<tof*r+(n-tof)*b<<endl;
	cout<<out<<endl;
}