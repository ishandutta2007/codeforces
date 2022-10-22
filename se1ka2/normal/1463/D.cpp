#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b[400005];
        for(int i = 0; i < n * 2; i++) b[i] = false;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            b[--a] = true;
        }
        int l = 0;
        int ans = n + 1;
        for(int i = 0; i < n * 2; i++){
            if(b[i]) l++;
            else l--;
            if(l == -1){
                ans--;
                l = 0;
            }
        }
        l = 0;
        for(int i = n * 2 - 1; i >= 0; i--){
            if(b[i]) l++;
            else l--;
            if(l == -1){
                ans--;
                l = 0;
            }
        }
        cout << ans << endl;
    }
}