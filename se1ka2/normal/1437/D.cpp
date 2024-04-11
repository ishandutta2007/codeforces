#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int c1 = 0, c2 = 1;
        int ans = 1;
        for(int i = 2; i < n; i++){
            if(a[i] > a[i - 1]){
                c2++;
            }
            else if(c1){
                c1--;
                c2++;
            }
            else{
                ans++;
                c1 = c2 - 1;
                c2 = 1;
            }
        }
        cout << ans << endl;
    }
}