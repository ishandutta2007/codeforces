#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,ll> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int p=1e9+7;
const int N=100000+19;
const int oo=(1<<30)-1;

int Pow(ll a,int b,int p){
	int res=1;
	for (a%=p;b;b>>=1,a=a*a%p) if (b&1) res=res*a%p;
	return res;
}

set<pii> S;
int n,m,seed,vmax,o,l,r,x,y,ans;

int rnd(){
	int tmp=seed;
	seed=(7ll*seed+13)%p;
	return tmp;
}
void gao(int x){
	pii P=*--S.lower_bound(mp(x+1,-oo));
	if (P.fi==x) return;
	S.insert(mp(x,P.se));
}
void Output(){
	static int seq[N];
	for (pii A:S){
		For(i,A.fi,n+1) seq[i]=A.se;
	}
	For(i,1,n+1) printf("%d ",seq[i]);
	puts("");
}

int main(){
	n=IN(),m=IN(),seed=IN(),vmax=IN();
	For(i,1,n+1){
		S.insert(mp(i,rnd()%vmax+1));
	}
	S.insert(mp(n+1,0));
	//Output();
	while (m--){
		o=rnd()%4+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if (l>r) swap(l,r);
		if (o==3) x=rnd()%(r-l+1)+1;else x=rnd()%vmax+1;
		if (o==4) y=rnd()%vmax+1;
		gao(l);
		gao(r+1);
	//	dprintf("	%d %d %d %d %d\n",o,l,r,x,y);
		if (o==1){
			for (int w=l;w<=r;){
				auto it=S.lower_bound(mp(w,-oo));
				pii P=*it;
				w=(++it)->fi;
				S.erase(P);
				S.insert(mp(P.fi,P.se+x));
			}
		} lf (o==2){
			for (int w=l;w<=r;){
				auto it=S.lower_bound(mp(w,-oo)),it2=it;
				it2++;
				w=it2->fi;
				S.erase(it);
			}
			S.insert(mp(l,x));
		} lf (o==3){
			vector<pair<ll,int> > V;
			for (int w=l;w<=r;){
				auto it=S.lower_bound(mp(w,-oo)),it2=it;
				it2++;
				V.pb(mp(it->se,it2->fi-w));
				w=it2->fi;
			}
			sort(V.begin(),V.end());
			For(i,0,V.size())
				if (x<=V[i].se){
					printf("%I64d\n",V[i].fi);
					break;
				} else{
					x-=V[i].se;
				}
		} lf (o==4){
			ans=0;
			for (int w=l;w<=r;){
				auto it=S.lower_bound(mp(w,-oo)),it2=it;
				it2++;
				ans=(ans+1ll*Pow(it->se,x,y)*(it2->fi-w))%y;
				w=it2->fi;
			}
			printf("%d\n",ans);
		}
		//Output();
	}
}