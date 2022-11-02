#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100
#define MM 333
int a[NN], b[NN], c[NN], d[NN], id[NN];
int *st[MM], *ed[MM], mn[MM];
int pre[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) gn(a[i], b[i]), gn(c[i], d[i]), id[i]=i;
	
	sort(id+1, id+n+1, [](int i, int j){return a[i]<a[j];});
	
	int M=(int)sqrt(n);
	int m=0;
	
	for(int i=1; i<=n; i+=M){
		st[m]=id+i;
		ed[m]=min(st[m]+M, id+n+1);
		mn[m]=a[id[i]];
		sort(st[m], ed[m], [](int i, int j){return b[i]<b[j];});
		m++;
	}
	
	queue <int> q;
	q.push(0);
	
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==n){
			VI ans;
			while(u) ans.pb(u), u=pre[u];
			printf("%d\n", (int)ans.size());
			for(int i=ans.size(); i--; ) printf("%d ", ans[i]);
			return 0;
		}
		int x=c[u], y=d[u];
		for(int i=0; i<m; i++) if(mn[i]<=x){
			int *it;
			VI vec;
			for(it=st[i]; it!=ed[i]; it++){
				if(b[*it]>y) break;
				if(a[*it]>x) vec.pb(*it);
				else q.push(*it), pre[*it]=u;
			}
			st[i]=it;
			for(int j=vec.size(); j--; ) *(--st[i])=vec[j];
		}
	}
	puts("-1");
	
	return 0;
}