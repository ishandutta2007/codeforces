#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
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

#define N 200007

int n, m, c, u, usable;

int p[N];

int s[N];

bitset<N> used;

int a[N]; //adaptery podpiete to socketu

int b[N]; //numer socketu dla komputera

map<int, VI> M;

int main()
{
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];

		M[p[i]].pb(i);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> s[i];
	}

	map<int, VI>::iterator it;

	usable = m;

	while(usable>0)
	{
		for(int i = 1; i <= m; ++i)
		{
			if(used[i] || s[i]==0)
				continue;

			it = M.find(s[i]);

			if(it!=M.end() && !(*it).nd.empty())
			{
				b[(*it).nd.back()] = i;
				(*it).nd.pop_back();
				used[i] = 1;
				--usable;
				++c;
				u += a[i];
			}
			else
			{
				if(s[i]==(s[i]+1)/2)
				{
					--usable;
					s[i] = 0;
				}
				else
				{
					s[i] = (s[i]+1)/2;
					++a[i];
				}
			}
		}
	}

	cout << c << " " << u << endl;

	for(int i = 1; i <= m; ++i)
	{
		if(used[i])
			cout << a[i] << " ";
		else
			cout << 0 << " ";
	}

	cout << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << b[i] << " ";
	}
}