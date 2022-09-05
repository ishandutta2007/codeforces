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

const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod=1000000007;

double dp[100007];

double a[100007];

int main(){
    int n;
    cin >> n;
    
    double p = 0.0;
    
    FOR(i,0,n)
              cin >> a[i];
    
    dp[0] = a[0];
    p = a[0];
    
    FOR(i,1,n){
               dp[i] = dp[i - 1] + a[i] + 2.0 * p * a[i];
               p = a[i] * (p + 1.0);           
    }

    
    printf("%.10f",dp[n - 1]);
    
    //system("pause");
    return 0;
}