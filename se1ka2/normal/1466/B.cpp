#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[200005];
        for(int i = 0; i <= n * 2 + 2; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            b[x]++;
        }
        int ans = 0;
        bool f = false;
        for(int i = 0; i <= n * 2 + 1; i++){
            if(b[i]) ans++;
            if(b[i] >= 2) f = true;
            if(!b[i]){
                ans += f;
                f = false;
            }
        }
        cout << ans << endl;
    }
}