#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll d[200105][10];
ll e[200105];

void add(int i){
    if(i == 0){
        d[0][0] = 1;
        return;
    }
    for(int j = 2; j < 10; j++) d[i][j] = d[i - 1][j - 1];
    d[i][0] = d[i - 1][9];
    d[i][1] = (d[i - 1][0] + d[i - 1][9]) % MOD;
    for(int j = 0; j < 10; j++) e[i] += d[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < 200100; i++) add(i);
    while(t--){
        int n, m;
        cin >> n >> m;
        ll ans = 0;
        while(n){
            int i = n % 10;
            n /= 10;
            ans += e[m + i];
        }
        cout << ans % MOD << "\n";
    }
}