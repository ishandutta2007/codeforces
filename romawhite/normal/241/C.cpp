#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
#include <time.h>

using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;

bool used[107];
int cost[107];

int top[100007];
int bot[100007];

int main() {
    int hl,hr,n;
    cin >> hl >> hr >> n;
    memset(top,-1,sizeof(top));
    memset(bot,-1,sizeof(bot));
    FOR(i,0,n){
        cin >> cost[i];
        char ch;
        cin >> ch;
        int l,r;
        cin >> l >> r;
        if (ch == 'T'){
            FOR(j,l,r)
                top[j] = i;
        }
        else{
            FOR(j,l,r)
                bot[j] = i;
        }
    }

    int res = 0;

    FOR(t,0,55){
        CLEAR(used);
        int H = 200 - hl - hr + 200 * t;

        bool q = 1;
        int c = 0;

        int h = 100 - hl;
        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (top[x] == -1 || used[top[x]]){
                q = 0;
                break;
            }
            else{
                used[top[x]] = 1;
                c += cost[top[x]];
            }
            h += 200;
        }

        h = 200 - hl;

        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (bot[x] == -1 || used[bot[x]]){
                q = 0;
                break;
            }
            else{
                used[bot[x]] = 1;
                c += cost[bot[x]];
            }
            h += 200;
        }

        if (q){
            res = max(res,c);
            //cout << c << endl;
        }

    }



    FOR(t,0,55){
        CLEAR(used);
        int H = 100 - hl + 100 + 200 * t + hr;

        bool q = 1;
        int c = 0;

        int h = 100 - hl;
        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (top[x] == -1 || used[top[x]]){
                q = 0;
                break;
            }
            else{
                used[top[x]] = 1;
                c += cost[top[x]];
            }
            h += 200;
        }

        h = 200 - hl;

        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (bot[x] == -1 || used[bot[x]]){
                q = 0;
                break;
            }
            else{
                used[bot[x]] = 1;
                c += cost[bot[x]];
            }
            h += 200;
        }

                if (q){
            res = max(res,c);
            //cout << c << endl;
        }

    }


    FOR(t,0,55){
        CLEAR(used);
        int H = hl + hr + 200 * t;
        bool q = 1;
        int c = 0;

        int h = hl;
        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (bot[x] == -1 || used[bot[x]]){
                q = 0;
                break;
            }
            else{
                used[bot[x]] = 1;
                c += cost[bot[x]];
            }
            h += 200;
        }

        h = hl + 100;

        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (top[x] == -1 || used[top[x]]){
                q = 0;
                break;
            }
            else{
                used[top[x]] = 1;
                c += cost[top[x]];
            }
            h += 200;
        }

        if (!t){
            //cout << q << ' ' << c << endl;
        }

        if (q){
            res = max(res,c);
            //cout << c << endl;
        }

    }


    FOR(t,0,55){
        CLEAR(used);
        int H = hl + 100 - hr + 200 * t + 100;

        bool q = 1;
        int c = 0;

        int h = hl;
        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (bot[x] == -1 || used[bot[x]]){
                q = 0;
                break;
            }
            else{
                used[bot[x]] = 1;
                c += cost[bot[x]];
            }
            h += 200;
        }

        h = hl + 100;

        FOR(i,0,t + 7){
            if (h > H) break;
            int x = 100000 * h / H;
            if (top[x] == -1 || used[top[x]]){
                q = 0;
                break;
            }
            else{
                used[top[x]] = 1;
                c += cost[top[x]];
            }
            h += 200;
        }

                if (q){
            res = max(res,c);
            //cout << c << endl;
        }

    }

    cout << res << endl;

    return 0;
}