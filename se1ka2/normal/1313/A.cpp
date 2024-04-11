#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        int ans = 0;
        for(int i = 0; i < 3; i++){
            if(a[i]){
                a[i]--;
                ans++;
            }
        }
        sort(a, a + 3);
        if(a[0] == 0){
            if(a[1]) cout << ans + 1 << endl;
            else cout << ans << endl;
        }
        if(a[0] == 1){
            if(a[2] >= 2) cout << ans + 2 << endl;
            else cout << ans + 1 << endl;
        }
        if(a[0] == 2) cout << ans + 3 << endl;
        if(a[0] >= 3)  cout << ans + 4 << endl;
    }
}