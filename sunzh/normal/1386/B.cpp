#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#include<cmath>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define double long double
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int Sx,Sy,Sz;
double sx,sy,sz;
int n;
int cnt=0;
int sum=0;
struct node{
	double x,y;
	bool operator <(const node &r)const{
		return x==r.x?y<r.y:x<r.x;;
	}
}a[500010];
typedef long long ll;
node b[500010];
int xd;
node stk[500010];
int top;
bool del[500010];
multiset<node>st;
const double pi=acosl(-1.0),eps=1e-8;
multiset<double>S;
struct Nd{
	ll x,y,z;
	bool operator <(const Nd &t)const{
		if(x==t.x)
			if(y==t.y)
				return z<t.z;
			else return y<t.y;
		else return x<t.x;
	} 
}at[500010];
map<Nd,int >M;
map<node,int>Map;
node operator -(node x,node y){
	return node{x.x-y.x,x.y-y.y};
}
void getans(){
	if(Map[node{0,0}]){
		printf("1\n");return ;
	}
	if(xd){
		printf("2\n");return ;
	}
	if(S.size()<3){
		printf("0\n");return ;
	}
	if(*(--S.end())-*(S.begin())<pi+eps){
		printf("0\n");return ;
	}
	auto it=S.lower_bound(0.0);
	if(it==S.begin()||it==S.end()){
		printf("0\n");return ;
	}
	auto it1=it;--it1;
	if(*it-*it1>pi+eps){
		printf("0\n");
		return ;
	}
	printf("3\n");
}
Nd operator -(Nd y){
	return Nd{-y.x,-y.y,-y.z};
}
int main(){
	Sx=read(),Sy=read(),Sz=read();
	double s=Sx+Sy+Sz;sx=Sx/s,sy=Sy/s,sz=1-sx-sy;
	n=read();
	while(n--){
		char c=getchar();
		while(c!='A'&&c!='R') c=getchar();
		if(c=='A'){
			int x=read(),y=read(),z=read();
			double s=x+y+z;
			ll X=1ll*y*Sz-1ll*z*Sy,Y=1ll*z*Sx-1ll*x*Sz,Z=1ll*x*Sy-1ll*y*Sx;
			a[++cnt]=node{x/s-sx,y/s-sy};
			++Map[a[cnt]];
			st.insert(a[cnt]);S.insert(atan2l(a[cnt].x,a[cnt].y)); 
			if(X==0&&Y==0&&Z==0){
				goto as ;
			}
			ll P=__gcd(X,__gcd(Y,Z));
//			printf("X:%lld,Y:%lld,Z:%lld\n",X,Y,Z);
			P=(P==0?1:P);if(P<0) P=-P;at[cnt]=Nd{X/P,Y/P,Z/P};
			++M[at[cnt]];
//			printf("%d %d %d\n",at[cnt].x,at[cnt].y,at[cnt].z);
			if(M[at[cnt]]==1){
				if(M[ -at[cnt]]>0) ++xd;
			}
//			printf("xd:%d\n",xd);
//			printf("%d\n",xd);
		}
		else{
			int x=read();del[x]=1;--Map[a[x]];
//			auto it=st.lower_bound(a[x]);st.erase(it);
			auto i=S.lower_bound(atan2l(a[x].x,a[x].y));
//			printf("%d %d\n",i==S.begin(),i==S.end());
			S.erase(i); 
			if(at[x].x==0&&at[x].y==0&&at[x].z==0) goto as ;
			--M[at[x]];
//			printf("%d %d %d %d %d\n",at[x].x,at[x].y,at[x].z,M[at[x]],M[-at[x]]);
			if(M[at[x]]==0){
				if(M[-at[x]]>0) --xd;
			}
//			printf("xd:%d\n",xd);
		}
		as:;getans();
	}
}