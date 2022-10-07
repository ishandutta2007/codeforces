#include<cstdio>
#include<cstring>
#include<iostream>
#define N 200005
#include<algorithm>
#include<set>
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,m;
int a[N],b[N],p[N];
struct Node {
	int v,p;
	bool operator < (const Node x) const {
		return v < x.v;
	}
};
set<Node> Set[4];
set<Node> ::iterator it;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);
	rep(i,1,n) read(p[i]);
	rep(i,1,n) read(b[i]);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) {
		Node u; u.v=p[i]; u.p=i;
		Set[a[i]].insert(u);
		if (a[i]!=b[i]) Set[b[i]].insert(u);
	}
	read(m);
	rep(i,1,m) {
		int x; read(x);
		if (Set[x].begin()==Set[x].end()) {printf("-1 "); continue;}
		it=Set[x].begin();
		int pos=(*it).p; printf("%d ",(*it).v);
		Set[x].erase(it);
		if (a[pos]!=b[pos]) {
			Node v=*it;
			if (a[pos]!=x) Set[a[pos]].erase(v);
			if (b[pos]!=x) Set[b[pos]].erase(v);			
		}
	}
	return 0;
}