#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

set<pii> st;
map<int, int> mp;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, Q;
	gn(n, Q);
	st.insert(pii(0, 0));
	st.insert(pii(n+1, 1));
	
	while(Q--) {
		int x, y;
		char s;
		scanf("%d %d %c", &x, &y, &s);
		if(mp.count(x)) {
			printf("%d\n", 0);
			continue;
		}
        if(s == 'L') {
			pii p = *--st.lower_bound(pii(x, 0));
			if(p.y == 0) mp[x] = x - p.x;
			else mp[x] = mp[p.x] + x - p.x;
			st.insert(pii(x, 1));
		} else {
			pii p = *st.lower_bound(pii(x, 0));
			if(p.y == 0) mp[x] = mp[p.x] + p.x - x;
			else mp[x] = p.x - x;
			st.insert(pii(x, 0));
		}
		printf("%d\n", mp[x]);
	}
	
}