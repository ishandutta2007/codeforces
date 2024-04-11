#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << a[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        return 0;
    }
    cout << 1 << " " << 1 << endl;
    cout << a[0] * (n - 1) << endl;
    cout << 2 << " " << n << endl;
    for(int i = 1; i < n; i++) cout << a[i] * (n - 1) << " ";
    cout << endl;
    cout << 1 << " " << n << endl;
    for(int i = 0; i < n; i++) cout << -a[i] * n << " ";
    cout << endl;
}