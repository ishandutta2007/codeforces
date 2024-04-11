#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll d[32]{0};
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        int c = 0;
        while(a % 2 == 0){
            a /= 2;
            c++;
        }
        d[c]++;
    }
    ll p[200005];
    p[0] = 1;
    for(int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;
    int s = d[0];
    ll ans = (p[d[0]] - 1) * p[n - s] % MOD;
    for(int i = 1; i < 30; i++){
        s += d[i];
        if(d[i]) ans = (ans + (p[d[i] - 1] - 1) * p[n - s]) % MOD;
    }
    cout << ans << endl;
}