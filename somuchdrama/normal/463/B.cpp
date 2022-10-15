#include <iostream>

using namespace std;

int main(){
    int n, ans=0, h;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> h;
        if(ans < h)
            ans = h;
    }
    cout << ans;
    return 0;
}