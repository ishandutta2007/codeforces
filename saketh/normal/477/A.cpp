#include <iostream>
using namespace std;

long long A, B;

int main(){
    cin >> A >> B;

    long long ans = 0;
    for(long long rem = 1; rem < B; rem++){
        long long triang = A * (A+1) / 2;
        triang = triang % 1000000007;
        triang = (triang * rem) % 1000000007;
        triang = (triang * B) % 1000000007;
        triang = (triang + rem * A) % 1000000007;
        ans = (ans + triang) % 1000000007;
    }

    cout << ans << endl;
}