#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<long long,long long> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 3;

pii a[nmax],b[nmax];

double dist(pii a, pii b){
    return sqrt(sqr(a.fs-b.fs) + sqr(a.sc-b.sc));
}

pii operator-(pii a, pii b){
    return pii(a.fs-b.fs,a.sc-b.sc);
}

long long smul(pii a, pii b){
    return a.fs*b.sc - a.sc*b.fs;
}

long long vmul(pii a, pii b){
    return a.fs*b.fs + a.sc*b.sc;
}


bool angle(pii a, pii b, pii c){
    long long q = smul(b-a,c-a);
    long long w = vmul(b-a,c-a);
//  cerr << q <<" " << w << endl;
    return (q != 0 && w >= 0);
}
    
bool good(pii a, pii b, pii c){
    if ((b.fs - a.fs) * (c.sc - b.sc) != (b.sc - a.sc) * (c.fs - b.fs)) return 0;
    if (a > b) swap(a,b);
    if (c < a || c > b) return 0;
    double q = dist(a,c);
    double w = dist(b,c);
    if (q > w) swap(q,w);
    return  (q / w) >= 0.25;
}

void solve(){
    long long n = 3;
    forn(i,n)
        cin >> a[i].fs >> a[i].sc >> b[i].fs >> b[i].sc;
    forn(i,n)
        forn(j,n)
            if (i != j){
                if (a[i] == b[j])
                    swap(a[j],b[j]);
                if (b[i] == a[j] || b[i] == b[j])
                    swap(a[i],b[i]);
                if (a[i] == b[j])
                    swap(a[j],b[j]);
                if (a[i] != a[j]) continue;
                if (!angle(a[i],b[i],b[j])) continue;
                long long k = 0;
                while (k == i || k == j) k++;
                if (! ((good(a[i],b[i],a[k]) && good(a[j],b[j],b[k])) || (good(a[i],b[i],b[k]) && good(a[j],b[j],a[k]))))
                    continue;
                puts("YES");
                return;
            }
    puts("NO");
}

int main(){
 //   freopen(inp.data(), "rt", stdin);
   // freopen(oup.data(),"wt", stdout);

    long long tst;
    cin >> tst;
    forn(i,tst){
//      cerr << "test" << endl;
        solve();
    }

    return 0;
}