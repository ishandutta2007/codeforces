#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

template <typename T>
class BIT {
    public:
    int n;
    vector<T> tree;
    
    BIT() {}
    BIT(int _n) {
        n = _n;
        tree.assign(n + 2, 0);
    }
 
    void add(int x, T v) {
        ++x;
        for (; x <= n; x += x&-x)
            tree[x] += v;
    }
 
    T psum(int x) {
        ++x;
        T sum = 0;
        for (; x > 0; x -= x&-x)
            sum += tree[x];
        return sum;
    }
};

template <typename T>
class RangeBIT {
    public:
    BIT<T> b1, b2;

    RangeBIT(int _n) {
        b1 = BIT<T>(_n);
        b2 = BIT<T>(_n);
    }

    void radd(int l, int r, T v) {
        b1.add(l, v); b1.add(r+1, -v);
        b2.add(l, (l-1)*v); b2.add(r+1, -r*v);
    }

    T psum(int x) {
        return b1.psum(x) * x - b2.psum(x);
    }

    T rsum(int l, int r) {
        return psum(r) - psum(l-1);
    }
};

int n;
string s;

LL solve() {
    RangeBIT<LL> rbit(n);
    vector<PI> v;
    LL f = 0;
    REP(i, n) {
        if (s[i]=='1'){
            PI a;
            if (i == 0 || s[i-1] == '0') {
                a = MP(i, 1);
            } else {
                a = v.back(); v.pop_back();
                a.S++;
            }

            PI b = v.size() ? v.back() : MP(-1,0);
            int p = 0;
            if (v.size()) {
                if (a.S < b.S) {
                    p = b.F + b.S + 1 - a.S;
                } else if (a.S == b.S) {
                    p = b.F + 1;
                    v.pop_back();
                } else { } // no reach
            }
            rbit.radd(p, i, 1);
            v.PB(a);
        }
        f += rbit.psum(i);
    }
    return f;
}

int main() {
    setIO();
    cin>>n>>s;
    cout<<solve()<<"\n";
    return 0;
}