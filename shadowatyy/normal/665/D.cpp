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

int n, Max, c1;

int res1 = -1, res1_1 = -1;

pair<int, int> res2 = {-1, -1};

pair<int, int> res2_1 = {-1, -1};

int t[1007];

bitset<2000007> sieve;

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];

        if(t[i]==1)
            c1++;

        Max = max(Max, t[i]);
    }

    sieve[1] = 1;

    for(int i = 2; i*i <= 2*Max; ++i)
    {
        if(!sieve[i])
        {
            for(int j = i*i; j <= 2*Max; j += i)
            {
                sieve[j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!sieve[t[i]])
        {
            res1 = t[i];
            break;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!sieve[t[i]+1] && c1 && t[i]!=1)
        {
            res1_1 = t[i];
            break;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            if(!sieve[t[i]+t[j]])
            {
                res2 = {t[i], t[j]};
            }

            if(!sieve[t[i]+t[j]] && !sieve[t[i]+1] && !sieve[t[j]+1] && c1 && t[i]!=1 && t[j]!=1)
            {
                res2_1 = {t[i], t[j]};
            }
        }
    }

    //////////////////////////////////////////////////////////////////////

    if(res2_1!=mp(-1, -1))
    {
        cout << 2 + c1 << endl << res2_1.st << " " << res2_1.nd << " ";

        for(int i = 1; i <= c1; ++i)
        {
            cout << 1 << " ";
        }

        return 0;
    }

    if(res1_1!=-1 && c1>1)
    {
        cout << 1 + c1 << endl << res1_1 << " ";

        for(int i = 1; i <= c1; ++i)
        {
            cout << 1 << " ";
        }

        return 0;
    }

    if(c1>2)
    {
        cout << c1 << endl;

        for(int i = 1; i <= c1; ++i)
        {
            cout << 1 << " ";
        }

        return 0;
    }

    if(res2!=mp(-1, -1))
    {
        cout << 2 << endl << res2.st << " " << res2.nd;

        return 0;
    }

    if(res1_1!=-1)
    {
        cout << 1 + c1 << endl << res1_1 << " ";

        for(int i = 1; i <= c1; ++i)
        {
            cout << 1 << " ";
        }

        return 0;
    }

    if(res1!=-1)
    {
        cout << 1 << endl << res1;

        return 0;
    }

    cout << 1 << endl << t[1];


}