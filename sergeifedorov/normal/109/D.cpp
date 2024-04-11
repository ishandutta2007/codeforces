#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

map<int, bool> good;
map<pii, int> end;
map<pii, int> now;

const int nmax = 100100;

int n;
pii a[nmax], e[nmax];
vector<pii> res;


void gen(long long now){
    if (now > 1e9)
        return;
    if (now != 0)
        good[now] = 1;
    gen(now * 10 + 4);
    gen(now * 10 + 7);
}

void move(pii q, int pos){
    if (now[q] == pos)
        return;
    int p = now[q];


    res.pb(mp(p, pos));
    pii w = a[pos];

    now[w] = p;
    now[q] = pos;

    swap(a[pos], a[p]);
}


bool done(){
    forn(i, n)
        if (a[i] != e[i])
            return 0;
    return 1;
}

void write(){
    cout << res.size() << endl;
    forn(i, res.size())
        printf("%d %d\n", res[i].fs+1, res[i].sc+1);
}


int main ()
{
    gen (0);
    cin >> n;
    forn(i, n){
        scanf("%d", &a[i].fs);      
        a[i].sc = i;
        e[i] = a[i];
    }
    sort(e, e + n);
    if (done()){
        write();
        exit(0);
    }

    pii pos = mp(-1, -1);
    forn(i, n)
        if (good[a[i].fs])
            pos = a[i];
    if (pos.fs == -1){
        puts("-1");
        exit(0);
    }

    forn(i, n)
        now[a[i]] = i;

    forn(i, n)
        if (e[i] != pos && e[i] != a[i]){
//          cerr << i << endl;
            
            move(pos, i);
            move(e[i], i);

/*          forn(i, n)
                cerr << a[i].fs << " " << a[i].sc << endl;
            cerr << endl;
            forn(i, n)
                cerr << e[i].fs << " " << e[i].sc << endl;
            cerr << endl;
*/      
        }
    assert(done());
    write();

    return 0;
}