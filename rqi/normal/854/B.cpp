#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if(k== 0){
        cout << 0 << ' ' << 0;
    }
    else{
        if(n/k < 3){
            if(k != n){
                cout << 1;
            }
            else cout << 0;
            cout << ' '<<n-k;
        }
        else{
            cout << 1 << ' '<< 2*k;
        }
    }
}