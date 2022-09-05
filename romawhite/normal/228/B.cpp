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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const long double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;

int main(){
    //freopen("kgraph.in","r",stdin);
    //freopen("kgraph.out","w",stdout);   
    int a[55][55];
    int b[55][55];
    int n1,m1,n2,m2;
    cin >> n1 >> m1;
    FOR(i,0,n1){
        string s;
        cin >> s;
        FOR(j,0,m1)
            a[i][j] = s[j] - '0';
    }

    cin >> n2 >> m2;
    FOR(i,0,n2){
        string s;
        cin >> s;
        FOR(j,0,m2)
            b[i][j] = s[j] - '0';
    }

    int idx,idy,M = -1;

    FOR(x,-55,55)
        FOR(y,-55,55){
            int r = 0;
            FOR(i,0,n1)
                FOR(j,0,m1)
                    if (i + x >= 0 && y + j >= 0 && i + x < n2 && j + y < m2)
                        r += a[i][j] * b[i + x][j + y];

        if (r > M){
            M = r;
            idx = x;
            idy = y;
        }

    }

    cout << idx << ' ' << idy;

    return 0;
}