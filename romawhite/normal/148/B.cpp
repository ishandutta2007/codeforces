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


int main(){
    double v1,v2,c,f,t;
    cin >> v1 >> v2 >> t >> f >> c;
    if (v2<=v1) {cout << 0; return 0;}
    double x=(v1*v2*t)/(v2-v1);
    int res=0;
    while (x+1e-9<c){
        x=(x+v1*x/v2+v1*f)*v2/(v2-v1);
        res++;
    }
    cout << res;
    return 0;
}