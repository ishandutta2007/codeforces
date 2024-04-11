#include <iostream>
using namespace std;
typedef long long ll;

ll a[100005];
ll d[100005];
ll s[100005];

int main()
{
    int n, q, k;
    cin >> n >> q >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n - 1; i++) d[i] = a[i + 1] - a[i - 1] - 2;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + d[i - 1];
    while(q--){
        int l, r;
        cin >> l >> r;
        r--;
        if(l > r) cout << k - 1 << endl;
        else cout << s[r] - s[l] + (a[l] - 2) + (k - 1 - a[r - 1]) << endl;
    }
}