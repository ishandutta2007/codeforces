#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int S=200;
const ll oo=1ll<<60;

struct node{
	int a,b;
	bool operator < (const node &B) const{
		return b<B.b;
	}
} P[N];

int A[N],id[N];
int n,w,c,B;
pair<ll,int> res;

struct Vector{
	int x;
	ll y;
	int id;
	ll At(int v) const{
		return 1ll*x*v+y;
	}
} V[N];

Vector operator - (Vector A,Vector B){
	return (Vector){A.x-B.x,A.y-B.y,0};
}
inline ll cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

struct Block{
	int s[S+19];
	int L,R,t,c,tag;
	pair<ll,int> ans;
	Block(){
		L=(1<<30)-1;
		R=-1;
	}
	void Renew(){
		for (;c+1<=t&&V[s[c]].At(tag)<V[s[c+1]].At(tag);c++);
		ans=mp(V[s[c]].At(tag),V[s[c]].id);
	}
	void Rebuild(){
		if (tag){
			For(i,L,R+1) V[i].y+=1ll*tag*V[i].x;
			tag=0;
		}
		t=0;
		For(i,L,R+1){
			for (;t>=2&&cross(V[s[t-1]]-V[s[t]],V[i]-V[s[t]])<0;t--);
			s[++t]=i;
		}
		c=1;
		Renew();
	}
} Bl[N/S+19];

int main(){
	n=IN(),w=IN();
	For(i,1,n+1){
		P[i]=(node){IN(),IN()};
		A[++*A]=P[i].a;
		B=max(B,P[i].b);
	}
	A[++*A]=0;
	sort(A+1,A+*A+1);
	*A=unique(A+1,A+*A+1)-A-1;
	For(i,1,n+1){
		P[i].a=lower_bound(A+1,A+*A+1,P[i].a)-A;
	}
	sort(P+1,P+n+1);
	c=1;
	For(i,1,*A+1) V[i]=(Vector){A[i],0,-i};
	For(i,1,*A+1){
		id[i]=i/S+1;
		Bl[id[i]].L=min(Bl[id[i]].L,i);
		Bl[id[i]].R=max(Bl[id[i]].R,i);
	}
	For(i,1,id[*A]+1){
		Bl[i].Rebuild();
	}
	For(i,0,B+2){
		res=mp(-oo,0);
		For(j,1,id[*A]+1) res=max(res,Bl[j].ans);
		res.fi+=1ll*i*w*(n-c+1);
		printf("%I64d %d\n",res.fi,A[-res.se]);
		for (;c<=n&&P[c].b==i;c++){
			int u=id[P[c].a];
			For(j,1,u){
				Bl[j].tag++;
				Bl[j].Renew();
			}
			For(j,Bl[u].L,P[c].a+1) V[j].y+=V[j].x;
			Bl[u].Rebuild();
		}
	}
}