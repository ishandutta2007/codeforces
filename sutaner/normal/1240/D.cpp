    #include <bits/stdc++.h>
    #define maxn 400019
    #define maxr 1000000
    #define rep(i, l, r) for (register int i = l; i <= r; i++)
    #define per(i, r, l) for (register int i = r; i >= l; i--)
    #define rep(i, l, r) for (register int i = l; i <= r; i++)
    #define per(i, r, l) for (register int i = r; i >= l; i--)
    #define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
    #define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
    #define ll long long int 
    #define pii pair<int, int>
    #define fi first
    #define se second
    #define H 1000000007
    using namespace std;
     
    char buffer[maxr], *p1, *p2;
    template <class T> void read(T& x){
    	char ch = gc(); x = 0; bool f = 1;
    	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    	if (ch == '-') f = 0, ch = gc();
    	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    	x = (f) ? x : -x;
    }
    int n;
    int a[maxn], b[maxn];
    map<ll, int> s;
    ll ans = 0;
     
    int sta[maxn];
    ll has[maxn];
    int head = 0;
    void solve(int l, int r){
    	if (l == r) return;
    	int mid = ((r - l) >> 1) + l;
    	solve(l, mid), solve(mid + 1, r);
    	head = 0;
    	per(i, mid, l) {
    		if (head && sta[head] == a[i]) head--;
    		else {
    			sta[++head] = a[i];
    			has[head] = (has[head - 1] * H) + b[a[i]]; 
    		}
    		s[has[head]]++;
    	}
    	head = 0;
    	rep(i, mid + 1, r){
    		if (head && sta[head] == a[i]) head--;
    		else {
    			sta[++head] = a[i];
    			has[head] = (has[head - 1] * H) + b[a[i]]; 
    		}
    		ans += s[has[head]];
    	}
    	s.clear();
    }
     
    int main(){
    	int T;
    	read(T);
    	while (T--){
    		read(n);
    		rep(i, 1, n) read(a[i]), b[i] = i;
    		solve(1, n);
    		printf("%lld\n", ans);
    		ans = 0;
    	}
    	return 0;
    }