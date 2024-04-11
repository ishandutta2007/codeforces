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

int n, m, a, b, Count[2], resR, resB;

vector<int> vecR[2];
vector<int> vecB[2];

vector<int> resultB;
vector<int> resultR;

bool wrongR, wrongB;

char c;

vector<pair<int, char> > G[100007];

bitset<100007> visR;
bitset<100007> visB;

int R[100007];
int B[100007];

void dfsR(int v)
{
    visR[v] = 1;

    ++Count[R[v]];

    vecR[R[v]].pb(v);

    for(auto it:G[v])
    {
        if(!visR[it.st])
        {
            if(it.nd=='R')
                R[it.st] = R[v];
            else
                R[it.st] = R[v]^1;

            dfsR(it.st);
        }
    }
}

void dfsB(int v)
{
    visB[v] = 1;

    ++Count[B[v]];

    vecB[B[v]].pb(v);

    for(auto it:G[v])
    {
        if(!visB[it.st])
        {
            if(it.nd=='B')
                B[it.st] = B[v];
            else
                B[it.st] = B[v]^1;

            dfsB(it.st);
        }
    }
}

int main()
{
    cin >> n >> m;

    while(m--)
    {
        cin >> a >> b >> c;

        G[a].eb(b, c);
        G[b].eb(a, c);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!visR[i])
        {
            Count[0] = 0;
            Count[1] = 0;

            vecR[0].clear();
            vecR[1].clear();

            dfsR(i);

            if(Count[0]<Count[1])
            {
                resultR.insert(resultR.end(), vecR[0].begin(), vecR[0].end());
            }
            else
            {
                resultR.insert(resultR.end(), vecR[1].begin(), vecR[1].end());
            }

            resR += min(Count[0], Count[1]);
        }


        if(!visB[i])
        {
            Count[0] = 0;
            Count[1] = 0;

            vecB[0].clear();
            vecB[1].clear();

            dfsB(i);

            if(Count[0]<Count[1])
            {
                resultB.insert(resultB.end(), vecB[0].begin(), vecB[0].end());
            }
            else
            {
                resultB.insert(resultB.end(), vecB[1].begin(), vecB[1].end());
            }

            resB += min(Count[0], Count[1]);
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(auto it:G[i])
        {
            if(it.nd=='R' && R[i]!=R[it.st])
                wrongR = 1;

            if(it.nd=='B' && R[i]==R[it.st])
                wrongR = 1;

            if(it.nd=='B' && B[i]!=B[it.st])
                wrongB = 1;

            if(it.nd=='R' && B[i]==B[it.st])
                wrongB = 1;
        }
    }

    if(wrongB && wrongR)
    {
        cout << -1;
        return 0;
    }

    if(wrongB)
        resB = inf;

    if(wrongR)
        resR = inf;

    if(resR<resB)
    {
        cout << resR << endl;

        for(auto it:resultR)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << resB << endl;

        for(auto it:resultB)
        {
            cout << it << " ";
        }
    }
}