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

const int MX = 200005;
int dec[MX];
int n;
string s;

LL solve() {
    int f[1111] = {0};
    LL r = 0;
    int i = (n-1)/2, j = n/2;
    cout << i << ", " << j << " = " << r << endl;
    while (i >= 0) {
        if (s[i] != s[j]) {
            int d = j - i;
            r += d - f[s[i]];
            r += d - 1 - f[s[j]];
        }
        f[s[i]]++;
        if (i!=j) f[s[j]]++;
        cout << i << ", " << j << " = " << r << endl;
        i--; j++;
    }
    return r;
    // Hmm.. this didn't work 
}

LL solve2() {
    set<int> S[26];
    REP(i, n) {
        int k = s[i] - 'a';
        S[k].insert(i);
    }
    int i = 0, j = s.length() - 1;
    LL r = 0;
    int k = 0, is = 0, js = 0;
    while (i < j) {
        int ki = s[i] - 'a';
        int kj = s[j] - 'a';
        
        int aj = *S[kj].begin();
        S[kj].erase(aj);

        int bi = *S[ki].rbegin();
        S[ki].erase(bi);

        if (s[i] != s[j]) {
            r += (aj - i) + (j - bi) - 1;
        }

        cout << aj << ", " << bi << ", r = " << r << endl;
        
        ++i; --j; ++k;
    }
    return r;
    // Hmm.. this didn't work either
}

LL solve3() {
    LL f[26] = {0};
    REP(i, n) {
        int k = s[i] - 'a';
        f[k] += i;
    }

    reverse(s.begin(), s.end());
    REP(i, n) {
        int k = s[i] - 'a';
        f[k] -= i;
    }

    LL r = 0;
    REP(i, 26) r += abs(f[i]);
    return r/2;
    // Nope.. failed #3
}

class BIT {
    public:
    int n;
    vector<int> tree;
    
    BIT(int _n) {
        n = _n;
        tree.resize(n + 2, 0);
    }

    void update(int x, int v) {
        ++x;
        for (; x <= n; x += x&-x)
            tree[x] += v;
    }

    int read(int x) {
        ++x;
        int sum = 0;
        for (; x > 0; x -= x&-x)
            sum += tree[x];
        return sum;
    }
};


LL solve4() {
    vector<deque<int>> pos(26);
    REP(i, n) {
        int k = s[i] - 'a';
        pos[k].push_back(n-1-i);
    }
    LL ans = 0;
    BIT bit(n);
    REP(i, n) {
        int k = s[n-1-i] - 'a';
        int p = *pos[k].begin();
        pos[k].pop_front();
        ans += bit.read(p);
        bit.update(p, 1);
    }
    return ans;
}

int main() {
    setIO();
    cin>>n>>s;
    // cout<<solve()<<"\n";    
    // cout<<solve2()<<"\n";    
    // cout<<solve3()<< "\n";
    cout << solve4() << endl;
    return 0;
}