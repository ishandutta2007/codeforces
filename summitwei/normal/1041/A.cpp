#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int l = INF, r = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        l = min(l, x);
        r = max(r, x);
    }
    
    int num = r-l+1;
    cout << num-n << "\n";

    return 0;
}