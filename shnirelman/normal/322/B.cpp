#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int r, g, b;
    cin >> r >> b >> g;

    int ans = 0;
    for(int i = 0; i < 3; i++)
        if(min(r, min(b, g)) >= i){
            ans = max(ans, i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3);
        }

    cout << ans;
}