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

const int nmax = 6000;

int n,w,h;
pair<pii,int> a[nmax];
int t[nmax];
int p[nmax];

int main(){
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> w >> h;
    forn(i,n){
        scanf("%d %d", &a[i].fs.fs, &a[i].fs.sc);
        a[i].sc = i;
    }
    sort(a, a + n);
    memset(t, 0, sizeof t);
    memset(p, 255, sizeof p);
    int res = 0;
    int pos = -1;
    for (int i = 0; i < n; i++){
        if (t[i] == 0 && a[i].fs.fs > w && a[i].fs.sc > h)
            t[i] = 1;
        if (t[i] == 0) continue;
        if (t[i] > res){
            res = t[i];
            pos = i;
        }
        for (int j = i + 1; j < n; j++)
            if (a[j].fs.sc > a[i].fs.sc && a[j].fs.fs > a[i].fs.fs && t[j] < t[i] + 1){
                t[j] = t[i] + 1;
                p[j] = i;
            }
    }
    cout << res << endl;
    if (res == 0) exit(0);
    vector<int> q;
    while (pos >= 0){
        q.pb(pos);
        pos = p[pos];
    }
    ford(i,q.size())
        printf("%d ", a[q[i]].sc+1);
    puts("");
    return 0;   
}