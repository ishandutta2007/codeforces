#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--;
            bool f = false;
            for(int i = 0; i < l; i++){
                if(s[i] == s[l]) f = true;
            }
            for(int i = r; i < n; i++){
                if(s[i] == s[r - 1]) f = true;
            }
            if(f) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}