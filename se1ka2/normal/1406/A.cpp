#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[102]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            b[a]++;
        }
        bool f = true;
        int ans = 0;
        for(int i = 0; i < 102; i++){
            if(b[i] == 0){
                break;
            }
            if(f && b[i] >= 2) ans += 2;
            else{
                f = false;
                ans++;
            }
        }
        cout << ans << endl;
    }
}