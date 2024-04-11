#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int n1 = n;
    long long a = 0;
    while(n1 > 0){
        a = a * 10 + 9;
        n1 /= 10;
    }

    if(a == n * 2 - 1){
        cout << 1;
        return 0;
    }

    if(n * 2 - 1 < a)a /= 10;

    long long ans = 0;
    for(int i = 0; i < 10; i++){
        if(a + a * i + i <= n + 1)ans += (a + a * i + i - 1) / 2;
        else if(a + a * i + i <= 2 * n - 1)ans += (2 * n + 1 - (a + a * i + i)) / 2;
        //cout << a << ' ' << (a + a * i + i) << ' ' << ans << endl;
    }

    cout << ans;
}