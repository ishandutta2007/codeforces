#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_PER 200005
#define MAX_N 2005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    ll gcd = __gcd(x, y);
    x = x/gcd;
    y = y/gcd;

    ll one = a/x, two = b/y;
    
    cout << min(one, two) << "\n";
    return 0;
}