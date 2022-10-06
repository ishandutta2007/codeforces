#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
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
typedef pair<int,Pii> PP;
typedef long long ll;
typedef long double ld;
const int N = 500005;
int n,a[N],ans;
multiset<pair<int,Pii> > s;
struct node {
	int cnt,pos;
	bool operator < (const node &a) const {
		if (cnt!=a.cnt) return cnt>a.cnt;
		return pos<a.pos;
	}
};
multiset<node> shan;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) {
		int j;
		for (j=i+1; j<=n; j++) if (a[j]!=a[i]) break;
		//[i,j-1]
		node u; u.cnt=j-i; u.pos=i;
		shan.insert(u); s.insert(PP(i,Pii(a[i],j-i)));
		i=j-1;
	}
	while (!shan.empty()) { ans++;
	//    printf("%u %u\n",shan.size(),s.size());
		multiset<node> ::iterator IT=shan.begin();
		int Pos=(*IT).pos; shan.erase(IT);
		multiset<pair<int,Pii> > ::iterator it=s.lower_bound(PP(Pos,Pii(0,0))),pre,nxt;
		pre=it; pre--;//if (it!=s.begin()) pre--; 
		nxt=it; nxt++; //huiyichuma????????????
		
		if (it==s.begin() || nxt==s.end() || (*pre).se.fi!=(*nxt).se.fi) {
		        s.erase(it); continue;
		}
		s.erase(it);
		int pos=(*pre).fi,val=(*pre).se.fi,cnt=(*pre).se.se+(*nxt).se.se;
		IT=shan.find((node){(*pre).se.se,pos}); shan.erase(IT);
		IT=shan.find((node){(*nxt).se.se,(*nxt).fi}); shan.erase(IT);
		shan.insert(node{cnt,pos}); 
		s.erase(pre); s.erase(nxt);
		s.insert(PP(pos,Pii(val,cnt)));
	}
	cout<<ans;
	return 0;
}