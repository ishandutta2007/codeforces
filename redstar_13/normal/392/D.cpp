#include<bits/stdc++.h>

#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define inf 0x3f3f3f3f

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100111
int a[NN], b[NN], c[NN];
int n;
int arr[NN<<2];
int nn;
int pos[3][NN<<2];

inline int get(int a) {
	return upper_bound(arr, arr+nn, a) - arr;
}

set<pii> s;
multiset<int> val;

void disp(set<pii> :: iterator it) {
	cerr<<it->x<<' '<<it->y<<endl;
}
inline set<pii> :: iterator del(set<pii> :: iterator it) {
	auto pre=it, nxt=it;
	pre--; nxt++;
//	cerr<<"del ------->"<<endl;
//	disp(pre); disp(it); disp(nxt);
	val.erase(val.find(pre->x+it->y));
	val.erase(val.find(it->x+nxt->y));
	val.insert(pre->x + nxt->y);
	s.erase(it);
//	cerr<<*val.begin()<<endl;
	return pre;
}


inline void add(int x, int y) {
	s.insert(pii(x, y));
	auto it = s.lower_bound(pii(x, y));
	auto pre=it, nxt=it;
	pre--; nxt++;
//	cerr<<"add ------->"<<endl;
//	disp(pre); disp(it); disp(nxt);
	val.insert(pre->x+it->y);
	val.insert(it->x+nxt->y);
	val.erase(val.find(pre->x + nxt->y));
//	cerr<<*val.begin()<<endl;
//	cerr<<x<<' '<<y<<' '<<*val.begin()<<endl;
}

inline void update(int x, int y) {
	auto it = s.upper_bound(pii(x, y));
	if(it->y>=y) return ;
	 --it;
	while(it->y<=y) {
		it = del(it);
	}
	add(x, y);
}

int solve() {
	cin >> n;
	for(int i=1; i<=n; i++) gn(a[i]), arr[nn++] = a[i];
	for(int i=1; i<=n; i++) gn(b[i]), arr[nn++] = b[i];
	for(int i=1; i<=n; i++) gn(c[i]), arr[nn++] = c[i];
	sort(arr, arr+nn); nn=unique(arr, arr+nn) - arr;
	memset(pos, 0x3f, sizeof pos);
	s.insert(pii(0, inf+1));
	s.insert(pii(inf+1, 0));
	val.insert(0); 
	for(int i=n; i>=1; i--) {
		a[i] = get(a[i]);
		pos[0][a[i]] = i;
	}
	for(int i=n; i>=1; i--) {
		b[i] = get(b[i]);
		pos[1][b[i]] = i;
	}
	for(int i=n; i>=1; i--) {
		c[i] = get(c[i]);
		pos[2][c[i]] = i;
	}
	for(int i=1; i<=nn; i++) if(pos[0][i] == inf) update(pos[1][i], pos[2][i]);
	int ans=inf;
	for(int i=n; i>=0; i--) {
		smin(ans, *val.begin()+i);
		if(i and pos[0][a[i]] == i) update(pos[1][a[i]], pos[2][a[i]]);
	}
	cout << ans << endl;
	
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif	
	solve();
	return 0;
}