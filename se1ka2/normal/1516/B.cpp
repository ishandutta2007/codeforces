#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int s[2002];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i - 1];
        bool f = false;
        for(int m = 1; m < n; m++){
            if(s[m] == (s[n] ^ s[m])) f = true;
        }
        for(int l = 1; l < n; l++){
            for(int r = l; r < n; r++){
                if(s[l] == (s[r] ^ s[l]) && (s[r] ^ s[l]) == (s[n] ^ s[r])){
                    f = true;
                }
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}