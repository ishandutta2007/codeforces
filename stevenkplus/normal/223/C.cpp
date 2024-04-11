#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<plli, vector<plli>, greater<plli> > PQ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
const ll infl = 1LL << 60;
char buf[1000000];
string nextLine() {
    scanf("%[^\n]", buf);
//  getc(stdin);
    scanf("%*c");
    return string(buf);
}
string next() {
    scanf("%s", buf);
    return string(buf);
}

int nextInt() {
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}
const int MAXN = 2100;
int chooses[MAXN];
int inverses[MAXN];
int K;
int N;
const ll MOD = 1E9 + 7;
/* This function return the gcd of a and b followed by
 the pair x and y of equation ax + by = gcd(a,b)*/
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while (a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

int modInverse(int a) {
    int m = MOD;
    return (extendedEuclid(a, m).second.first + m) % m;
}

ll times(ll a, ll b) {
    return (a * b) % MOD;
}
ll divide(ll a, ll b) {
    return times(a, inverses[b]);
}
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
void prec() {
    rep(i,N+1) {
        inverses[i] = modInverse(i);
    }
    ll c = 1;
    int mult = K;
    rep(i,N+1) {
        chooses[i] = c;
        c = times(c, mult);
        c = divide(c, i + 1);
        mult--;
    }
}

int sums[MAXN][MAXN];

int main() {
    N = nextInt();
    K = nextInt();
    prec();
    rep(i,N) {
        sums[0][i] = nextInt();
    }
    repr(i,1,N) {
        sums[i][0] = sums[i - 1][0];
        repr(j,1,N) {
            sums[i][j] = add(sums[i][j - 1], sums[i - 1][j]);
        }
    }
    string sep;
    rep(i,N) {
        int x = 0;
        int y = i;
        ll guy = 0;
        rep(k,i+1) {
            guy = add(guy, times(chooses[k], sums[x][y]));
            x++;
            y--;
        }
        cout << sep << guy;
        sep = " ";
    }
    cout << "\n";

}