#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) { *s = __c; } *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) { x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; } return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) { qu[++ qr] = x % 10 + '0',  x /= 10; } while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

constexpr int B = 666;
constexpr int N = 500000;

int n, q;
int ar[500005], loc[500005], tmp[500005];
int ans[N/B+5][N/B+5];
pii dt[500005];

vector<int> res;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gi(n), gi(q);
    {
        map<int, int> t;
        rep(i, n) {
            int v; gi(v);
            if(!t.count(v)) t[v] = i;
            ar[i] = t[v];
            dt[i] = {ar[i], i};
        }
        sort(dt, dt+n);
        rep(i, n) loc[dt[i].se] = i;
        for(int l=0,b=0; l<n; l+=B,b++) {
            memset(tmp, 0, sizeof tmp);
            int cans = 0;
            iter(r, l, n) {
                cans = max(cans, ++tmp[ar[r]]);
                if(r%B==B-1) ans[b][r/B] = cans;
            }
        }
    }
    int la = 0;
    while(q--) {
        int l, r, cans = 0; gi(l), gi(r);
        l--; r--;
        if(l/B == r/B)
            iter(i, l, r+1)
                while(loc[i]+cans < n && dt[loc[i]+cans].fi == ar[i] && dt[loc[i]+cans].se <= r) 
                    cans++;
        else {
            int nl = l + (l%B?B-l%B:0), nr = r - (r+1)%B; cans = ans[nl/B][nr/B];
            iter(i, l, nl)
                while(loc[i]+cans < n && dt[loc[i]+cans].fi == ar[i] && dt[loc[i]+cans].se <= r) 
                    cans++;
            iter(i, nr+1, r+1)
                while(0 <= loc[i]-cans && dt[loc[i]-cans].fi == ar[i] && l <= dt[loc[i]-cans].se)
                    cans++;
        }
        int len=r-l+1;
        if(cans<=(len+1)/2)
        {
        	res.push_back(1);
        	continue;
		}
		int s=len-cans;
		res.push_back(len-2*s);
    }
    for(int i:res)
        cout<<i<<endl;
    return 0;
}