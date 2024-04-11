#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d[4];
        for(int i = 0; i < 4; i++) cin >> d[i];
        bool ans = false;
        for(int b = 0; b < (1 << 4); b++){
            bool f = true;
            for(int i = 0; i < 4; i++){
                if(d[i] == 0){
                    if((b >> i) & 1 || (b >> ((i + 1) % 4)) & 1) f = false;
                }
                if(d[i] == 1){
                    if((b >> i) & 1 && (b >> ((i + 1) % 4)) & 1) f = false;
                }
                if(d[i] == n - 1){
                    if(!((b >> i) & 1) && !((b >> ((i + 1) % 4)) & 1)) f = false;
                }
                if(d[i] == n){
                    if(!((b >> i) & 1) || !((b >> ((i + 1) % 4)) & 1)) f = false;
                }
            }
            ans |= f;
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}