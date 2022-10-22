#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, s, p;
    cin >> k >> n >> s >> p;

    int ans = k * (n / s + (n % s > 0));
    ans = ans / p + (ans % p > 0);

    cout << ans;

}