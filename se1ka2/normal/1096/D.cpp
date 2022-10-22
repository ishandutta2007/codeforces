#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000000;
const char c[4] = {'h', 'a', 'r', 'd'};

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll dp[5]{0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(s[i] == c[j]){
                dp[j + 1] = min(dp[j + 1], dp[j]);
                dp[j] += a[i];
            }
        }
    }
    ll ans = INF;
    for(int j = 0; j < 4; j++) ans = min(ans, dp[j]);
    cout << ans << endl;
}