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



int main() {
    int n,k;
    int a[100];
    cin >> n >> k;
    FOR(i,0,n)
        cin >> a[i];
    int b = k-1;
    while (b<n-1 && a[b+1] == a[b]) b++;
    while (b>=0 && a[b] == 0) b--;
    cout << b+1;
    return 0;
}