#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a[3];
        for(int i = 0; i < 3; i++) cin >> a[i];
        sort(a, a + 3);
        int ans = a[2] - a[1] + a[1] - a[0] + a[2] - a[0];
        ans = max(0, ans - 4);
        cout << ans << endl;
    }
}