//#pragma comment(linker, "/STACK:32777216")
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
#include <sstream>
#include <fstream>

 
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
const int mod = 1000000007;

vector<int> g[100007];
vector<pair<int,int> > e;

int h,t;
    vector<int> A;
    vector<int> B;
    vector<int> SAME;
void res1(int a,int b){
    cout << "YES\n";
    int i = 0;
    int j = 0;
    while (i < g[a].size() && j < g[b].size()){
        if (g[a][i] == b){
            ++i;
            continue;
        }
        if (g[b][j] == a){
            ++j;
            continue;
        }
        if (g[a][i] == g[b][j]){
            SAME.PB(g[a][i]);
            ++i;
            ++j;
            continue;
        }
        if (g[a][i] < g[b][j]){
            A.PB(g[a][i]);
            ++i;
            continue;
        }
        B.PB(g[b][j]);
        ++j;
    }
    FOR(I,i,g[a].size())
        if (g[a][I] != b)
            A.PB(g[a][I]);
    FOR(I,j,g[b].size())
        if (g[b][I] != a)
            B.PB(g[b][I]);

    bool sw = 0;
    if (h > t){
        sw = 1;
        swap(h,t);
    }

    if (sw)
        cout << b + 1 << ' ' << a + 1 << endl;
    else cout << a + 1 << ' ' << b + 1 << endl;

    if (sw){
        FOR(i,0,B.size()){
            cout << B[i] + 1<< ' ';
            t--;
            if (!t) break;
        }
        if (t)
        FOR(i,0,SAME.size()){
            cout << SAME[i] + 1<< ' ';
            t--;
            if (!t) break;
        }
        cout << endl;

        FOR(i,0,A.size()){
            cout << A[i] + 1<< ' ';
            h--;
            if (!h) break;
        }
        if (h)
        RFOR(i,SAME.size() , 0){
            cout << SAME[i] + 1<< ' ';
            h--;
            if (!h) break;
        }
        cout << endl;
    }
    else{
        FOR(i,0,A.size()){
            cout << A[i] + 1<< ' ';
            h--;
            if (!h) break;
        }
        if(h)
        RFOR(i,SAME.size() , 0){
            cout << SAME[i] + 1<< ' ';
            h--;
            if (!h) break;
        }
        cout << endl;

       FOR(i,0,B.size()){
            cout << B[i] + 1<< ' ';
            t--;
            if (!t) break;
        }
       if (t)
        FOR(i,0,SAME.size()){
            cout << SAME[i] + 1<< ' ';
            t--;
            if (!t) break;
        }
        cout << endl;
    }

};

int main() {
    //cout << 'y';
   int n,m;
   scanf("%d%d%d%d",&n,&m,&h,&t);
    FOR(i,0,100007)
        g[i].clear();
    e.clear();
    FOR(i,0,m){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].PB(b);

        g[b].PB(a);

        e.PB(MP(a,b));
    }
//cout << 'x';
    FOR(i,0,n)
        sort(ALL(g[i]));

    FOR(E,0,m){
        int a = e[E].first;
        int b = e[E].second;
        if (g[a].size() > g[b].size())
            swap(a,b);
        if (g[a].size() - 1 >= min(h,t) && g[b].size() - 1 >= h + t){
            res1(a,b);
            return 0;
        }
        if (g[a].size() - 1 < min(h,t) || g[b].size() - 1 < max(h,t))
            continue;
        int same = 0;
        int ii = 0;
        int jj = 0;
        while (ii < g[a].size() && jj < g[b].size()){
            if (g[a][ii] == g[b][jj]){
                ++same;
                ++ii;
                ++jj;
                continue;
            }
            if (g[a][ii] < g[b][jj]){
                ++ii;
                continue;
            }
            ++jj;
        }
        int s1 = g[a].size() - 1;
        int s2 = g[b].size() - 1;
        s1 -= same;
        s2 -= same;
        if (s1 < min(h,t)){
            same -= min(h,t) - s1;
        }
        if (same + s2 >= max(h,t)){
            res1(a,b);
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}