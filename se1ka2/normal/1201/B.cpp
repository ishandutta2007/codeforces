#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    ll sum = 0, lar = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        lar = max(lar, a[i]);
    }
    if(sum % 2 == 1 || lar * 2 > sum) cout << "NO" << endl;
    else cout << "YES" << endl;
}