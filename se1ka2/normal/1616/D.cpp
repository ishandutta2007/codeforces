#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[50002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int x;
        cin >> x;
        for(int i = 0; i < n; i++) a[i] -= x;
        bool f = true;
        int s = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < 0){
                if(!f && s + a[i] < 0){
                    f = true;
                    ans++;
                    s = 0;
                }
                else{
                    f = false;
                    s = a[i];
                }
            }
            else{
                if(!f && s + a[i] < 0){
                    f = true;
                    ans++;
                    s = 0;
                }
                else{
                    f = false;
                    s = min(0, s) + a[i];
                }
            }
        }
        cout << n - ans << endl;
    }
}