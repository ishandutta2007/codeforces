#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define pb push_back

struct Bigint2 {
	static const int LEN = 70;
	static const int BLEN = 30;
	static const int BIGMOD = 1<<BLEN;
	static const INT BIGMOD1 = 1LL<<(BLEN<<1);
	static const int bmod=BIGMOD-1;
	static const INT bmod1=BIGMOD1-1;

	int s, vl, v[LEN];
	void pb(int x) {v[vl ++] = x;}
	int len() const {return vl;}
	bool empty() const { return len() == 0 ; }
	void pop_back() {vl --;}
	int back() const {return v[vl - 1];}
	void n() {while (!empty() && !back()) pop_back(); if (empty()) s=1;}
	void resize(int nl) {vl = nl;memset(v, 0, sizeof(int) * (nl + 1));}

	Bigint2() : s(1) {vl = 0;}
	Bigint2(long long a) {
		s = 1; vl = 0;
		if (a < 0) {s = -1; a = -a;}
		while (a) {
			pb(a & bmod);
			a >>= BLEN;
		}
		n();
	}

	Bigint2(string str) {
		s = 1; vl = 0;
		int stPos = 0, num = 0;
		if (!str.empty() && str[0] == '-') {
			s = -1; stPos=1;
		}
		vector<int> vp;
		int tmod=(int)1e8;
		for (int i = str.size() - 1, q = 1; i >= stPos; i --) {
			num += (str[i] - '0') * q;
			if ((q*=10) >= tmod) {
				vp.pb(num);
				num = 0; q = 1;
			}
		}
		if (num) vp.pb(num);
		while (!vp.empty()) {
			INT r=0;
			for (int i=vp.size()-1; i>=0; i--) {
				r=r*tmod+vp[i];
				vp[i]=r>>BLEN; r&=bmod;
			}
			while (!vp.empty() && !vp.back()) vp.pop_back();
			pb(r);
		}
		n();
	}

	void print() const {
		if (empty()) {puts("0");return ;}
		int c=back(), la=1;
		printf("%o", c);
		for (int i = len() - 2; i >= 0; i --) printf("%.10o", v[i]); putchar('\n');
	}

	void print10() const {
		if (empty()) {puts("0");return ;}
		VI vp(1, 0), tp;
		if (s==-1) putchar('-');
		int tmod=(int)1e9;
		for (int i=len()-1; i>=0; i--) {
			INT r=0;
			tp=vp; vp.clear(); vp.resize(tp.size(), 0);
			for (int j=0; j<tp.size(); j++) {
				r=(INT)tp[j]*BIGMOD+vp[j];
				vp[j]=r%tmod; r/=tmod;
				for (int k=j+1; r; k++) {
					if (k==vp.size()) vp.pb(0);
					r+=vp[k];
					vp[k]=r%tmod; r/=tmod;
				}
			}
			r=v[i];
			for (int j=0; j<vp.size() && r; j++) {
				r+=vp[j]; vp[j]=r%tmod; r/=tmod;
			}
			if (r) vp.pb(r);
		}
		int c=vp.back();
		printf("%d", c);
		for (int i=vp.size()-2; i>=0; i--) printf("%.9d", vp[i]);puts("");
	}

	int cp3(const Bigint2 &b) const {
		if (s != b.s) return s - b.s;
		if (s == -1) return -(-*this).cp3(-b);
		if (len() != b.len()) return len() - b.len();
		for (int i = len() - 1; i >= 0; i --)
			if (v[i] != b.v[i]) return v[i] - b.v[i];
		return 0;
	}

	bool operator < (const Bigint2 &b) const { return cp3(b) < 0; }
	bool operator <= (const Bigint2 &b) const { return cp3(b) <= 0; }
	bool operator == (const Bigint2 &b) const { return cp3(b) == 0; }
	bool operator != (const Bigint2 &b) const { return cp3(b) != 0; }
	bool operator > (const Bigint2 &b) const { return cp3(b) > 0; }
	bool operator >= (const Bigint2 &b) const { return cp3(b) >= 0; }

	Bigint2 operator - () const {
		Bigint2 r = (*this);
		r.s = -r.s;
		if (r.len()==0) r.s=1;
		return r;
	}

	Bigint2 operator + (const Bigint2 &b) const {
		if (s == -1) return -(-(*this) + (-b));
		if (b.s == -1) return (*this) - (-b);
		Bigint2 r;
		int nl = max(len(), b.len());
		r.resize(nl + 1);
		for (int i = 0; i < nl; i ++) {
			if (i < len()) r.v[i] += v[i];
			if (i < b.len()) r.v[i] += b.v[i];
			if (r.v[i] >= BIGMOD) {
				r.v[i+1]++, r.v[i]&=bmod;
			}
		}
		r.n();
		return r;
	}

	Bigint2 operator - (const Bigint2 &b) const {
		if (s == -1) return -(-(*this) - (-b));
		if (b.s == -1) return (*this) + (-b);
		if ((*this) < b) return -(b - (*this));
		Bigint2 r;
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

	Bigint2 operator * (const Bigint2 &b) {
		Bigint2 r;
		r.resize(len() + b.len() + 1);
		r.s = s * b.s;
		INT c=0, up=0;
		for (int i=0; i<r.len(); i++) {
			c=up; up=0;
			for (int j=max(0, i-b.len()+1); j<len() && j<=i; j++) {
				c+=(INT)v[j]*b.v[i-j];
				if (c>=BIGMOD1) {
					up+=c>>BLEN; c&=bmod;
				}
			}
			up+=c>>BLEN; c&=bmod;
			r.v[i]=c;
		}
		r.n();
		return r;
	}

	Bigint2 operator / (const Bigint2 &b) {
		if (len()<b.len()) return 0;
		Bigint2 r;
		r.resize(max(1, len() - b.len() + 1));
		int oriS = s;
		Bigint2 b2 = b;
		Bigint2 a2 = *this, a3;
		a2.s = b2.s = r.s = 1;
		for (int i = r.len() - 1; i >= 0; i --) {
			INT d = 0, u = bmod;
			a3=a2>>(i*30);
			if (a3.len()>b2.len()) {
				INT r=((INT)a3.back()<<BLEN)+a3.v[a3.len()-2];
				u=r/b2.back()+1;
			} else if (a3.len()==b2.len() && b2.len()>1) {
				INT r=((INT)a3.back()<<BLEN)+a3.v[a3.len()-2];
				u=r/(((INT)b2.back()<<BLEN)+b2.v[b2.len()-2])+1;
			} else if (a3.len()==b2.len() && b2.len()==1) {
				u=a3.back()/b2.back()+1;
			}
			while (d < u) {
				INT m = (d + u + 1) >> 1;
				r.v[i] = m;
				if (((b2 * m)) > a3) u = m - 1;
				else d = m;
			}
			r.v[i] = d;
			a2=a2-((b2*d)<<i*30);
			a2.n();
		}
		s = oriS;
		r.s = s * b.s;
		r.n();
		return r;
	}

	Bigint2 operator % (const Bigint2 &b) {
		return (*this) - (*this) / b * b;
	}

	int len1() {
		return 32-__builtin_clz(back())+(len()-1)*30;
	}

	Bigint2 operator << (const int &u) {
		if (u==0) return *this;
		Bigint2 r;
		r.resize((len1()+u+29)/30);
		for (int V=u%30, i=r.len()-1, t=u/30; i>=t; i--) {
			r.v[i]=((i-t<len()?(INT)v[i-t]<<V:0)|(i-t?v[i-t-1]>>30-V:0))&bmod;
		}
		r.n();
		return r;
	}

	Bigint2 operator >> (const int &u) {
		int nn=len1();
		if (nn<=u) return 0;
		Bigint2 r; r.resize((nn-u+29)/30);
		for (int V=u%30, c=(1<<V)-1, i=u/30, j=0; j<r.len(); i++, j++) {
			r.v[j]=(v[i]>>V)|(i<len()-1?(v[i+1]&c)<<30-V:0);
		}
		r.n();
		return r;
	}
	
	Bigint2 operator ^ (const Bigint2 &u) {
	    int mx=max(len(), u.len());
	    Bigint2 r; r.resize(mx);
	    for (int i=0; i<mx; i++) {
	        if (i<len()) r.v[i]^=v[i];
	        if (i<u.len()) r.v[i]^=u.v[i];
        }
        r.n();
        return r;
    }
	
	int get(const int &x) {
	    if (x>=len1()) return 0;
	    return (v[x/30]>>(x%30))&1;
    }

    int count() {
        int ans=0;
        for (int i=0; i<len(); i++) ans+=__builtin_popcount(v[i]);
        return ans;
    }
};

char s[666];
const int NN = 2020;
Bigint2 id[NN], val[NN];
int pos[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int m;
    cin>>m;
    memset(pos, -1, sizeof pos);
    for (int i=0; i<m; i++) {
        scanf("%s", s);
        val[i] = Bigint2(s);
        int flag=0;
        for (int j=0; j<NN; j++) if (val[i].get(j)) {
            if (pos[j]==-1) {
                flag=1;
                pos[j]=i;
                break;
            }
            val[i]=val[i]^val[pos[j]];
            id[i]=id[i]^id[pos[j]];
            if (val[i]==0) break;
        }
        if (flag) {
            id[i]=id[i]^(Bigint2(1)<<i);
            puts("0");
            continue;
        }

        printf("%d", id[i].count());
        for (int j=0; j<NN; j++) if (id[i].get(j)) printf(" %d", j);
        puts("");
    }

    return 0;
}