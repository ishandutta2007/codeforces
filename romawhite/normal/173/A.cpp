#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

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
const int N = 10000005;

int main() {
    map<pair<char,char>,int> a;
    a[MP('R','S')] = 1;
    a[MP('S','P')] = 1;
    a[MP('P','R')] = 1;
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    int l = l1 * l2;
    int res1 = 0, res2 = 0;
    FOR(i,0,l){
        res1 += a[MP(s1[i%l1],s2[i%l2])];
        res2 += a[MP(s2[i%l2],s1[i%l1])];
    }
    res1 *= n/l;
    res2 *= n/l;
    FOR(i,0,n%l){
        res1 += a[MP(s1[i%l1],s2[i%l2])];
        res2 += a[MP(s2[i%l2],s1[i%l1])];
    }

    cout << res2 << ' ' << res1;
    return 0;
}