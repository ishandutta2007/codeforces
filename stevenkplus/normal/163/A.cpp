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
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
typedef pair<pii, int> circ;

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
char buf[1000];
string nextLine(int length = 100) {
    cin.getline(buf, length);
    string s(buf);
    return s;
}
string next(int length = 100) {
    string tmp;
    cin >> tmp;
    return tmp;
}

int nextInt() {
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}
ll mod = 1E9 + 7;
ll add(ll a, ll b) {
    return (a + b) % mod;
}

const int MAXN = 5010;
string s1, s2;
int m, n;
ll dp[MAXN][MAXN];
ll get(int starta, int startb) {
    if (starta == m)
        return 0;
    if (startb == n)
        return 0;
    ll &ret = dp[starta][startb];
    if (ret != -1)
        return ret;
    ret = 0;
    if (s2[startb] == s1[starta]) {
        ret++;
        ret = add(ret, get(starta + 1, startb + 1));
    }
    ret = add(ret, get(starta, startb + 1));
    return ret;
}
int main() {
    s1 = next();
    s2 = next();
    m=sz(s1);
    n=sz(s2);
    ll sum = 0;
    rep(i,MAXN) rep(j,MAXN) dp[i][j]=-1;
    rep(i,m) {
        sum = add(sum, get(i, 0));
    }
    cout << sum << endl;
}