#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const string task = "a";
const string inp = task + ".in";
const string outp = task + ".out";

int a[200];
int t,m;

void def(){
    int pos = 0;
    forn(i,m)
        if (a[i] != 0){
            int c = a[i];
            a[i] = 0;
            a[pos++] = c;
        }
}

void al(int n, int &x){
    forn(j,m-n+1){
        bool good = 1;
        forn(i,n)
            if (a[i+j] != 0)
                good = 0;
        if (!good) continue;
        cout << x << endl;
        forn(i,n)
            a[i+j] = x;
        x++;
        return;
    }
    puts("NULL");
}

void er(int64 x){
    bool done = 0;
    if (x > 0)
        forn(i,m)
            if (a[i] == x){
                done = 1;
                a[i] = 0;
            }
    if (!done)
        puts("ILLEGAL_ERASE_ARGUMENT");
}

int main(){
 //   freopen(inp.data(), "rt", stdin);
  //  freopen(outp.data(),"wt", stdout);

    cin >> t >> m;
    int id = 1;
    forn(i,t){
        string s;
        int64 x;
        cin >> s;
        if (s[0] == 'd'){
            def();
            continue;
        }
        cin >> x;
        if (s[0] == 'e')
            er(x);
        else
            al(x,id);
    }
        

    return 0;
}