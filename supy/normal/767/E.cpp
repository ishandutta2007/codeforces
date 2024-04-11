#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#include<queue>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 100005
int n,m;
ll ans;
int c[N],w[N],x[N];
bool a[N]; //1:spend 0:get

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
priority_queue<Pii,vector<Pii>,greater<Pii> > heap; //careful
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) {read(c[i]);x[i]=c[i]%100;}
	rep(i,1,n) read(w[i]);
	rep(i,1,n) {
		if (x[i]==0){a[i]=1;continue;}
		if (m>=x[i]) {
			m-=x[i]; a[i]=1;
			heap.push(mp(w[i]*(100-x[i]),i));
		}
		else {
			bool flag=0;
			if (heap.empty()) flag=1;
			else {
				Pii tmp=heap.top();
				if (tmp.fi>w[i]*(100-x[i])) flag=1;
				else {
					ans+=tmp.fi; m+=100-x[i]; //m
					a[i]=1; a[tmp.se]=0;
					heap.pop(); heap.push(mp(w[i]*(100-x[i]),i));
				}
			}
			if (flag==1) {
				a[i]=0; ans+=w[i]*(100-x[i]); m+=100-x[i];
			}
		}
	}
	cout<<ans<<endl;
	rep(i,1,n)
		if (a[i]==1) printf("%d %d\n",c[i]/100,x[i]);
		else printf("%d %d\n",c[i]/100+1,0);
	return 0;
}