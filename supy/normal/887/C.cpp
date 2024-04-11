#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 25;
struct E {int v[N];} s,t;
struct Que {int v1,v2,v3;} q[190000];
struct Hash {
	int mo,head[80000],nxt[80000],pos[80000],val[80000],edgenum; //!!!!!!!!!!!
	inline void clear() {
		memset(head,0,sizeof(head)); edgenum=0; mo=77777;
	}
	inline void insert(int key, int v) {
		pos[++edgenum]=key; val[edgenum]=v;
		nxt[edgenum]=head[key%mo];
		head[key%mo]=edgenum;
	}
	inline int find(int key) {
		int u=key%mo;
		for (int i=head[u]; i!=0; i=nxt[i]) if (pos[i]==key) return val[i];
		return -1;
	}
} Map;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
/*inline Que getque() {
	Que a;
	a.v1=0; rep(i,1,8) a.v1=a.v1*7+s[i];
	a.v1=0; rep(i,9,16) a.v1=a.v1*7+s[i];
	a.v1=0; rep(i,17,24) a.v1=a.v1*7+s[i];
	return a;
}
inline void getst(int v1, int v2, int v3) {
	int p=8; while (v1) {s[p--]=v1%7; v1/=7;}
	p=16; while (v2) {s[p--]=v2%7; v2/=7;}
	p=24; while (v3) {s[p--]=v3%7; v3/=7;}
}*/
inline bool ok(E s) {
	for (int i=1; i<=24; i+=4)
		if (s.v[i]!=s.v[i+1]||s.v[i]!=s.v[i+2]||s.v[i]!=s.v[i+3]||s.v[i+1]!=s.v[i+2]||s.v[i+1]!=s.v[i+3]||s.v[i+2]!=s.v[i+3])
			return 0;
	return 1;
}
inline void rotate(int a,int b,int c, int d, int e, int f, int g, int h) {
	//c,d,e,f,g,h,a,b
	int A=t.v[a],B=t.v[b];
	t.v[a]=t.v[c]; t.v[b]=t.v[d];
	t.v[c]=t.v[e]; t.v[d]=t.v[f];
	t.v[e]=t.v[g]; t.v[f]=t.v[h];
	t.v[g]=A; t.v[h]=B;
}
int main() {
	rep(i,1,24) read(s.v[i]);
	/*int f=0,r=1; q[0]=getque();
	while (f!=r) {
		Que u=q[f++]; getst(u.v1,u.v2,u.v3);
		..
	}*/
	bool flag=0;
	t=s;
	rotate(2,4,6,8,10,12,23,21);
	flag|=ok(t);
	t=s;
	rotate(21,23,12,10,8,6,4,2);
	flag|=ok(t);
	
	t=s;
	rotate(1,3,5,7,9,11,24,22);
	flag|=ok(t);
	t=s;
	rotate(22,24,11,9,7,5,3,1);
	flag|=ok(t);
	
	t=s;
	rotate(3,4,17,19,10,9,16,14);
	flag|=ok(t);
	t=s;
	rotate(14,16,9,10,19,17,4,3);
	flag|=ok(t);
	
	t=s;
	rotate(1,2,18,20,12,11,15,13);
	flag|=ok(t);
	t=s;
	rotate(13,15,11,12,20,18,2,1);
	flag|=ok(t);
	
	t=s;
	rotate(5,6,17,18,21,22,13,14);
	flag|=ok(t);
	t=s;
	rotate(14,13,22,21,18,17,6,5);
	flag|=ok(t);
	
	t=s;
	rotate(15,16,7,8,19,20,23,24);
	flag|=ok(t);
	t=s;
	rotate(24,23,20,19,8,7,16,15);
	flag|=ok(t);
	
	if (flag) puts("YES"); else puts("NO");
	return 0;
}