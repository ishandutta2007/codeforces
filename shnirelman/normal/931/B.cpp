#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    a--;
    b--;

    int ans = 1;
    while(a / 2 != b / 2){
        a /= 2;
        b /= 2;
        n /= 2;
        ans++;
    }

    if(n > 2)cout << ans;
    else cout << "Final!";
}