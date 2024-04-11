#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[5];
    a[0] = 100;
    a[1] = 20;
    a[2] = 10;
    a[3] = 5;
    a[4] = 1;

    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans += n / a[i];
        n %= a[i];
    }

    cout << ans;
}