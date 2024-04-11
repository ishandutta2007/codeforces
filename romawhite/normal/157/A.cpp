//#pragma comment(linker,"/STACK:16777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;

int main() {
    int n;
    cin >> n;
    int a[40][40];
    FOR(i,0,n)
        FOR(j,0,n)
            cin >> a[i][j];
    int res = 0;
    FOR(i,0,n)
        FOR(j,0,n){
            int s1 = 0;
            int s2 = 0;
            FOR(j1,0,n)
                s1+=a[i][j1];
            FOR(i1,0,n)
                s2+=a[i1][j];
            if (s1<s2)
                res++;
    }
    cout << res;
    return 0;
}