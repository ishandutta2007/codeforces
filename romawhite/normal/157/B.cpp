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
    double r[110];
    FOR(i,0,n)
        cin >> r[i];
    sort(r,r+n);
    double R = 0;
    for(int i = n-1; i>0; i-=2)
        R += r[i]*r[i] - r[i-1]*r[i-1];
    if (n%2) R+=r[0]*r[0];
    double res = R*pi;
    printf("%.10f",res);
    return 0;
}