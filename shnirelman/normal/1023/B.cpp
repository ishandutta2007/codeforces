#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    if(n == 1 || k - n > n - 1){
        cout << 0;
        return 0;
    }

    if(n >= k - 1){
        cout << (k - 1) / 2;
    }
    else {
        cout << (2 * n - k + 1) / 2;
    }
}