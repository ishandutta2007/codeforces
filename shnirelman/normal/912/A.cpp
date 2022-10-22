#include <iostream>

using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;

    long long a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    long long suma = a1 * 2 + a2, sumb = a2 + a3 * 3;

    long long ans = 0;
    if(suma > a)ans = suma - a;
    if(sumb > b)ans += sumb - b;

    cout << ans;

}