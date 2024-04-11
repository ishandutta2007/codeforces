#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, d;
        cin >> n >> d;
        bool f = false;
        for(ll i = 0; i < d; i++){
            if(i > (d - 1) / (i + 1) + 2) break;
            if(i + (d - 1) / (i + 1) + 1 <= n){
                cout << "Yes" << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << "No" << endl;
    }
}