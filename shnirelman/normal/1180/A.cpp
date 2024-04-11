#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    n--;

    int ans = 1 + n * 4;

    int a = 0;
    while(n > 0){
        ans += a * 4;
        a++;
        n--;
    }

    cout << ans;

}