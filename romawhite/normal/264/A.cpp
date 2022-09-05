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
#include <time.h>
#include <sstream>
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
const int INF=1000000007;
const LL mod= 1000000007;
const double EPS=1e-7;

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);
    vector<int> a; 
    vector<int> b;
    string s;
    cin >> s;
    FOR(i,0,s.size()){
        if (s[i] == 'l')
            b.push_back(i + 1);
        else a.PB(i + 1);
    }

    FOR(i,0,a.size())
        cout << a[i] << endl;
    RFOR(i,b.size() , 0)
        cout << b[i] << endl;

    return 0;
}