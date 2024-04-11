#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000009;

int main()
{
    int n[3];
    ll a[3][300005];
    ll s[3]{0};
    ll l[3];
    for(int i = 0; i < 3; i++) cin >> n[i];
    for(int i = 0; i < 3; i++){
        l[i] = INF;
        for(int j = 0; j < n[i]; j++){
            cin >> a[i][j];
            l[i] = min(l[i], a[i][j]);
            s[i] += a[i][j];
        }
    }
    sort(s, s + 3);
    sort(l, l + 3);
    cout << s[0] + s[1] + s[2] - min(s[0], l[0] + l[1]) * 2 << endl;
}