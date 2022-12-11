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
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

bool p[1010];
int n,k;
vector<int> e;

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(oup.data(),"wt", stdout);

    cin >> n >> k;
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        p[i] = 1;
        for (int j = 2; j < i; j++)
            if (i % j == 0){
                p[i] = 0;
                break;
            }
        if (p[i]){
            e.pb(i);
//          cerr << i << endl;
        }
    }
    forn(i,e.size()-1)
        if (e[i] + e[i+1] + 1 <= n && p[e[i] + e[i+1] + 1]) cnt ++;
//  cerr << e.size() << " " << cnt << endl;
    if (cnt >= k)
        puts("YES");
    else
        puts("NO");



    return 0;
}