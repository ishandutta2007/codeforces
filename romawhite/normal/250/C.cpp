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
#include <sstream>
#include <fstream>

 
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
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;

int c[100007];

int main() {
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,n){
        int j = i;
        while (j < a.size() && a[j] == a[i]) ++j;
        if (j == a.size() || !i || a[j] != a[i - 1]) ++c[a[i]];
        else c[a[i]] += 2;
        //cout << a[i] <<' ' << j << ' '<< c[a[i]] << endl;
        i = j - 1;
    }
    //cout << c[1] << ' ' << c[2] << ' ' << c[3] << endl;
    int Max = 0;
    int id;
    FOR(i,1,k + 1)
        if (c[i] > Max){
            Max = c[i];
            id = i;
        }
    cout << id << endl;

    return 0;
}