#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define x first
#define y second
#define pb push_back

int power(int a, int b, int c, int ans=1) {
	for (; b; b>>=1, a=(INT)a*a%c) if (b&1) ans=(INT)ans*a%c;
	return ans;
}

const int NN = 200111;
char s[NN];

struct Bigint {
	static const int LEN = 50000;
	static const int BIGMOD = 100000000;
	static const INT BIGMOD1 = 10000000000000000LL;

	int s, vl, v[LEN];
	void pb(int x) {v[vl ++] = x;}
	int len() const {return vl;}
	bool empty() const { return len() == 0 ;}
	void pop_back() {vl --;}
	int back() const {return v[vl - 1];}
	void n() {while (!empty() && !back()) pop_back();if (empty()) s=1;}
	void resize(int nl) {vl = nl;memset(v, 0, sizeof(int) * (nl + 1));}

	Bigint() : s(1) {vl = 0;}
	Bigint(long long a) {
		s = 1; vl = 0;
		if (a < 0) {s = -1; a = -a;}
		while (a) {
			pb(a % BIGMOD);
			a /= BIGMOD;
		}
		n();
	}
	Bigint(string str) {
		s = 1; vl = 0;
		int stPos = 0, num = 0;
		if (!str.empty() && str[0] == '-') {
			stPos = 1;
			s = -1;
		}
		for (int i = str.size() - 1, q = 1; i >= stPos; i --) {
			num += (str[i] - '0') * q;
			if ((q *= 10) >= BIGMOD) {
				pb(num);
				num = 0; q = 1;
			}
		}
		if (num) pb(num);
		n();
	}

	int print(char *t) {
		int c=back();
		int nt=0;
		for (int i = 0; i<=len()-2; i++) {
			int u=v[i];
			for(int j=0; j<8; j++) t[nt++] = u%10+'0', u/=10;
		}
		while(c) {
			t[nt++] = c%10+'0';
			c/=10;
		}
		reverse(t, t+nt);
		return nt;
	}

	int cp3(const Bigint &b) const {
		if (s != b.s) return s - b.s;
		if (s == -1) return -(-*this).cp3(-b);
		if (len() != b.len()) return len() - b.len();
		for (int i = len() - 1; i >= 0; i --)
			if (v[i] != b.v[i]) return v[i] - b.v[i];
		return 0;
	}

	bool operator < (const Bigint &b) const { return cp3(b) < 0; }
	bool operator <= (const Bigint &b) const { return cp3(b) <= 0; }
	bool operator == (const Bigint &b) const { return cp3(b) == 0; }
	bool operator != (const Bigint &b) const { return cp3(b) != 0; }
	bool operator > (const Bigint &b) const { return cp3(b) > 0; }
	bool operator >= (const Bigint &b) const { return cp3(b) >= 0; }

	Bigint operator - () const {
		Bigint r = (*this);
		r.s = -r.s;
		if (r.len()==0) r.s=1;
		return r;
	}

	Bigint operator + (const Bigint &b) const {
		if (s == -1) return -(-(*this) + (-b));
		if (b.s == -1) return (*this) - (-b);
		Bigint r;
		int nl = max(len(), b.len());
		r.resize(nl + 1);
		for (int i = 0; i < nl; i ++) {
			if (i < len()) r.v[i] += v[i];
			if (i < b.len()) r.v[i] += b.v[i];
			if (r.v[i] >= BIGMOD) {
				r.v[i+1]++, r.v[i]-=BIGMOD;
			}
		}
		r.n();
		return r;
	}

	Bigint operator - (const Bigint &b) const {
		if (s == -1) return -(-(*this) - (-b));
		if (b.s == -1) return (*this) + (-b);
		if ((*this) < b) return -(b - (*this));
		Bigint r;
		r.resize(len());
		for (int i = 0; i < len(); i ++) {
			r.v[i] += v[i];
			if (i < b.len()) r.v[i] -= b.v[i];
			if (r.v[i] < 0) {
				r.v[i] += BIGMOD ;
				r.v[i + 1] --;
			}
		}
		r.n();
		return r;
	}

	Bigint operator * (const Bigint &b) {
		Bigint r;
		r.resize(len() + b.len() + 1);
		r.s = s * b.s;
		INT c=0, up=0;
		for (int i=0; i<r.len(); i++) {
			c=up; up=0;
			for (int j=max(0, i-b.len()+1); j<len() && j<=i; j++) {
				c+=(INT)v[j]*b.v[i-j];
				if (c>=BIGMOD1) {
					up+=c/BIGMOD; c%=BIGMOD;
				}
			}
			up+=c/BIGMOD; c%=BIGMOD;
			r.v[i]=c;
		}
		r.n();
		return r;
	}

	Bigint operator / (const Bigint &b) {
		if (len()<b.len()) return 0;
		Bigint r;
		r.resize(max(1, len() - b.len() + 1));
		int oriS = s;
		Bigint b2 = b;
		s = b2.s = r.s = 1;
		for (int i = r.len() - 1; i >= 0; i --) {
			int d = 0, u = BIGMOD - 1;
			while (d < u) {
				int m = (d + u + 1) >> 1;
				r.v[i] = m;
				if ((r * b2) > (*this)) u = m - 1;
				else d = m;
			}
			r.v[i] = d;
		}
		s = oriS;
		r.s = s * b.s;
		r.n();
		return r;
	}

	Bigint operator % (const Bigint &b) {
		return (*this) - (*this) / b * b;
	}
};


char t[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	scanf("%s", s);
	Bigint a = Bigint(s);
	for(int i=0; i<n; i++) t[i] = s[i%k];
	Bigint b = Bigint(t);
	cout << n << endl;
	if(b >= a) return puts(t);
	s[k] = 0;
	Bigint c = Bigint(s);
	c = c+1;
	assert(c.print(t)==k);
	for(int i=0; i<n; i++) t[i] = t[i%k];
	puts(t);
	
	

	return 0;
}