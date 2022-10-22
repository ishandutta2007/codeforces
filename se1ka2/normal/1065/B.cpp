#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    cout << max(0ll, n - m * 2) << " ";
    for(ll i = 0; i <= 100000; i++){
        if(i * (i - 1) / 2 >= m){
            cout << n - i << endl;
            break;
        }
    }
}