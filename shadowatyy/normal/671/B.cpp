#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

static struct IO {

#define getc_unlocked getc
#define putc_unlocked putc

	char tmp[1 << 10];

	char cur;

	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

ll n, k, l, r, m, res_min, res_max, sum_c;

int t[500007];

bool Min(int a)
{
    ll sum = 0;

    REP(i, n)
    {
        sum += max(0, a-t[i]);
    }

    return sum<=k;
}

bool Max(int a)
{
    ll sum = 0;

    REP(i, n)
    {
        sum += max(0, t[i]-a);
    }

    return sum<=k;
}

int main()
{
    cin >> n >> k;

    REP(i, n)
    {
        cin >> t[i];

        sum_c += t[i];
    }

    l = 0, r = 1e9;

    while(l<r)
    {
        m = (l+r)/2;

        if(l==m)
            ++m;

        if(Min(m))
            l = m;
        else
            r = m-1;
    }

    res_min = l;

    l = 0, r = 1e9;

    while(l<r)
    {
        m = (l+r)/2;

        if(m==r)
            --m;

        if(Max(m))
            r = m;
        else
            l = m+1;
    }

    res_max = l;

    if(res_max<=res_min)
    {
        if(sum_c==((sum_c/n)*n))
        {
            cout << 0;
            return 0;
        }
        else
        {
            cout << 1;
            return 0;
        }
    }

    cout << res_max-res_min;
}