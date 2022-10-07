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
typedef pair<double, double> point;
const int MAXN = 110;
const double RAD = 5 / sin(36 * M_PI / 180);

vi stars[MAXN];
vector<point> points;
vi order;
int draw = 1;
point get(point center, double rot, double dist) {
    return point(center.fi + dist * sin(rot), center.se + dist * cos(rot));
}
void star(int s, point center, bool up) {
    int startd = draw-1;
    if (!s)
        return;
    double inc = 2 * M_PI / 5;
    double start = up ? 0 : inc / 2;
    point nextp = get(center, start, RAD);
    point nextc = get(nextp,36*M_PI/180,RAD);
    points.pb(nextp);
    order.pb(draw);
    stars[s-1].pb(draw);
    draw++;
    star(s - 1, nextc, up);

    for (int i = 2; i <= 6; i += 2) {
        nextp = get(center, start + i * inc, RAD);
        order.pb(draw);

        points.pb(nextp);
        stars[s-1].pb(draw);
        draw++;
    }
    order.pb(startd);
    stars[s-1].pb(startd);
}

int main() {
    point start = point(0, 0);
    point startv = get(start, 6*M_PI/5,RAD);
    points.pb(startv);
    order.pb(draw);
    draw++;

    int n= nextInt();
    star(n,start,true);
    printf("%d\n", sz(points));
    repi(p,points) {
        printf("%.20f %.20f\n", p->fi, p->se);
    }
    rep(ii,n) {
        int i = n-ii-1;
        string sep;
        rep(k,5) {
            int j = stars[i][k*3%5];
            printf("%s%d", sep.c_str(), j);
            sep = " ";
        }
        printf("\n");
    }
    string sep;
    repi(i,order) {
        printf("%s%d", sep.c_str(), *i);
        sep = " ";
    }
    printf("\n");
}