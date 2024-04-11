#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long n, q;
    cin >> n >> q;

    long long m = n * n / 2 + (n * n % 2);
    for(int i = 0; i < q; i++){
        long long x, y;
        cin >> x >> y;
        if((x + y) % 2 == 0){
            if(x % 2 != 0){
                cout << (x / 2 * n + y / 2 + 1) << endl;
            }
            else{
                cout << ((x - 1) / 2 * n + n / 2 + n % 2 + y / 2) << endl;
            }
        }
        else{
            if(x % 2 != 0){
                cout << (m + x / 2 * n + y / 2) << endl;
            }
            else{
                cout << (m + (x - 1) / 2 * n + n / 2 + y / 2 + 1) << endl;
            }
        }
    }
}