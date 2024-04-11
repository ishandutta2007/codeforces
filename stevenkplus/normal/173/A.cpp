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
//int ans();

bool big(char a, char b) {
    return (a == 'R' && b == 'S') || (a == 'S' && b == 'P')
            || (a == 'P' && b == 'R');
}
int main() {
    int N = nextInt();
    string a = next(), b = next();
    int per = sz(a) * sz(b);
    int mod = N % per;
    int reps = N / per;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    rep(i,per) {
        char aa = a[i % sz(a)], bb = b[i % sz(b)];
        if (aa == bb)
            continue;
        if (big(aa, bb)) {
            if (i < mod)
                x1++;
            x2++;
        } else {
            if (i < mod)
                y1++;
            y2++;
        }
    }
    cout << reps * y2 + y1 << " " << reps * x2 + x1 << endl;

}