#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,m,d,res,a[N],b[N];
set<Pii>Set;
int main() {
	read(n);read(m);read(d);rep(i,1,n)read(a[i]);
	rep(i,1,n)Set.insert(Pii(a[i],i));
	while(!Set.empty()){
		int s=(*Set.begin()).se;Set.erase(Set.begin());res++;
		while(1){
			b[s]=res;
			if(Set.empty())break;
			set<Pii>::iterator it=Set.lower_bound(Pii(a[s]+d+1,-1));
			if(it==Set.end())break;s=(*it).se;Set.erase(it);
		}
	}
	printf("%d\n",res);rep(i,1,n)printf("%d ",b[i]);
	return 0;
}