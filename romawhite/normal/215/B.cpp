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
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;
 
int a[100],b[100];
 
int main(){
    int n;
    cin >> n;
    double r1 = -1.0;
    double e;
    FOR(i,0,n){
        cin >> e;
        r1 = max(r1,e);
    }
    int m;
    cin >> m;
    double p1[5005];
    FOR(i,0,m){
        cin >> p1[i];
    }
    int k;
    cin >> k;
    double p2[5005];
    FOR(i,0,k){
        cin >> p2[i];
    }
    double A,B;
    cin >> A >> B;
    double res = -1.0;
    FOR(i,0,m)
        FOR(j,0,k){
            double r2 = (p1[i] * B) / (p1[i] * B + p2[j] * A);
            r2 = sqrt(r2);
            r2 *= r1;
            //cout << i << ' ' << j << ' ' << r2 << endl;
            res = max(res,r2);

    }
    printf("%.10f",res);
    return 0;
}