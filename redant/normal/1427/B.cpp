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

int n, k;
string st;

int solve() {
    VI s;
    int s0 = 0, s1 = 0;
    int score = 0;

    int i = 0;
    while (i < n && st[i] == 'L') {
        i++;
        s0++;
    }

    while (i < n) {
        score++;
        if (i > 0 && st[i-1] == 'W') score++;
        if (i+1 == n || st[i+1] == 'W') {
            i++;
            continue;
        }
        int j = i++;
        while (i < n && st[i] == 'L') {
            i++;
        }
        int kk = i - j - 1;
        if (i == n) s1 = kk;
        else s.PB(kk);
    }

    sort(ALL(s));
    for (int i = 0; i < s.size() && k > 0; i++) {
        int p = min(k, s[i]);
        score += 2 * p;
        if (p == s[i]) score++;
        k -= p;
    }

    if (score == 0) {
        if (k-- > 0) score++;
        score += 2 * max(0, min(k, s0 - 1));
    } else {
        score += 2 * max(0, min(k, s0 + s1));
    }

    return score;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        cin>>st;
        cout<<solve()<<"\n";
    }
    
    return 0;
}