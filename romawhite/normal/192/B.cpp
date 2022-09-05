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
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;


int main(){
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUT.TXT","w",stdout);
    int n;
    cin >> n;
    int a[1005];
    FOR(i,0,n)
        cin >> a[i];
    FOR(t,1,1005){
        if (t > a[0] || t > a[n-1]){
            cout << t-1;
            return 0;
        }
        FOR(j,0,n-1)
            if (t > a[j] && t > a[j+1]){
                cout << t-1;
                return 0;
            }
    }
    return 0;
}