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
int ar[10][10];
int main() {
    rep(i,2)
        rep(j,4)
            ar[i][j] = nextInt();
    int countt= 0;
    rep(i,2) {
        int cx = ar[1 - i][0], cy = ar[1 - i][1];
        int x = ar[i][0], y = ar[i][1];
        int d = (cx-x)*(cx-x)+(cy-y)*(cy-y);
        int r1 = ar[1-i][2],r2 = ar[1-i][3];
        rep(j,2) {
            int r = ar[i][2+j];
            if((d>=(r+r2)*(r+r2)&&d>=(r+r1)*(r+r1))||((r<=min(r1,r2)||r>=max(r1,r2)) &&(d<=(r1-r)*(r1-r))&&d<=(r2-r)*(r2-r))) {
//              printf("%d,%d, d=%d,r=%d,r1=%d,r2=%d\n",i,j,d,r,r1,r2);
                countt++;
            }
        }
    }
    cout<<countt;

}