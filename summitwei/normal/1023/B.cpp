#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005

int main(){
    ll n, k;
    
    cin >> n >> k;

    ll minAmt = max(k-n, (ll)1);
    ll maxAmt = min(n, k/2);
    if(k % 2 == 0 && k/2==maxAmt) maxAmt--;

    if(maxAmt < minAmt || k >= 2*n) cout << 0 << "\n";
    else cout << maxAmt - minAmt + 1 << "\n";

    return 0;
}