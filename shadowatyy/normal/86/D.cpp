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

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
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

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
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

const int block = 447;

int n, q, l, r;

int t[200007];

int c[1000007];

int a[200007];

int b[200007];

ll res[200007], curr_res;

VI vec;

bool comp(int i, int j)
{
    if(a[i]/block!=a[j]/block)
    {
        return a[i]<a[j];
    }

    return b[i]<b[j];
}

void insert(int p)
{
    curr_res -= (ll)c[t[p]]*c[t[p]]*t[p];

    ++c[t[p]];

    curr_res += (ll)c[t[p]]*c[t[p]]*t[p];
}

void remove(int p)
{
    curr_res -= (ll)c[t[p]]*c[t[p]]*t[p];

    --c[t[p]];

    curr_res += (ll)c[t[p]]*c[t[p]]*t[p];
}

void answear(int i)
{
    while(l<a[i])
    {
        remove(l);
        ++l;
    }

    while(l>a[i])
    {
        --l;
        insert(l);
    }

    while(r<b[i])
    {
        ++r;
        insert(r);
    }

    while(r>b[i])
    {
        remove(r);
        --r;
    }

    res[i] = curr_res;
}

int main()
{
    cin >> n >> q;

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];
    }

    for(int i = 1; i <= q; ++i)
    {
        cin >> a[i] >> b[i];

        vec.pb(i);
    }

    sort(vec.begin(), vec.end(), comp);

    for(int i = 0; i < q; ++i)
    {
        answear(vec[i]);
    }

    for(int i = 1; i <= q; ++i)
    {
        cout << res[i] << endl;
    }

}