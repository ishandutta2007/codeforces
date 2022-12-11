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

const int nmax = 100;

bool used[nmax][nmax];
int n,k;

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(oup.data(),"wt", stdout);

    cin >> n >> k;
    forn(qwe,n){
        int x;
        cin >> x;
        int res = 1e9;
        int r,lr,rr;
        r = -1;
        int xc,yc;
        xc = yc = k/2;
        forn(i,k){
            int p1,p2;
            p1 = 0;
            p2 = x-1;
            int cur = abs(xc - i) * x;
            int cnt=0;
            forn(j,x){
                if (used[i][j]) cnt++;
                cur = cur + abs(yc - j);
            }
            while(p2 < k){
                if (cnt == 0){
                    if (cur < res){
                        res = cur;
                        r = i;
                        lr = p1;
                        rr = p2;
                    }
                }
                cnt = cnt - used[i][p1] + used[i][p2+1];
                cur = cur - abs(p1 - yc) + abs(p2+1 - yc);
                p1++;
                p2++;
            }
        }
        if (r == -1)
            puts("-1");
        else{
            cout << r+1 << " " << lr+1 << " " << rr+1 << endl;
            for (int j = lr; j <= rr; j++)
                used[r][j] = 1;
        }
    }
    
    return 0;
}