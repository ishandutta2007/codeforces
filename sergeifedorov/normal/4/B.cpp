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

const int nmax = 1000;

int main(){
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    int d,t;
    int l[nmax], r[nmax];
    int sl, sr;
    sl = sr = 0;

    cin >> d >> t;
    forn(i,d){
        cin >> l[i] >> r[i];
        sl += l[i];
        sr += r[i];
    }
    if (t < sl || t > sr){
        puts("NO");
        exit(0);
    }
    puts("YES");
    forn(i,d){
        int now = l[i] + max(0, t - l[i] - (sr - r[i]));
        t -= now;
        sr -= r[i];
        cout << now << " ";
    }
    cout << endl;

    return 0;   
}