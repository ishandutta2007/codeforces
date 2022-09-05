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
    int k1,k2,k3,k4,n;
    cin >> k1 >> k2 >> k3 >> k4 >> n;
    vector <bool> q(n,0);
    for(int i=k1-1; i<n; i+=k1)
        q[i]=1;
    for(int i=k2-1; i<n; i+=k2)
        q[i]=1;
    for(int i=k3-1; i<n; i+=k3)
        q[i]=1;
    for(int i=k4-1; i<n; i+=k4)
        q[i]=1;
    int res=0;
    FOR(i,0,n)
        if (q[i]==1)
            res++;
    cout << res;
    return 0;
}