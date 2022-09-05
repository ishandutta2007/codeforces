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
#include <time.h>
#include <sstream>
#include <stack>
using namespace std;

#define next gdfsgvd
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
#define FILL(a,value) memset(a,value,sizeof(a))

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const LL INF=1000000000;
const LL mod= 1000000007;
const double EPS = 1e-7;

int main(){
    int n;
    cin >> n;
    int res = 0;
    FOR(i,0,n){
        int k , a;
        cin >> k >> a;
        LL t = 1;
        int l = 0;
        while (t < a){
            t *= 4;
            l++;
        }
        if (a == 1) l = 1;
        res = max(res , k + l);
    }

    cout << res << endl;
    return 0;
}