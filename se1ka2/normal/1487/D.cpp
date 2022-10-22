#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 3; i <= n; i += 2){
            if((i * i - 1) / 2 >= n) break;
            ans++;
        }
        cout << ans << endl;
    }
}