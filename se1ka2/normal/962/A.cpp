#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200002];
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll r = 0;
    for(int i = 0; i < n; i++){
        r += a[i];
        if(r * 2 >= s){
            cout << i + 1 << endl;
            return 0;
        }
    }
}