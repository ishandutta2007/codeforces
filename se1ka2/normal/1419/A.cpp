#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n % 2){
            bool f = false;
            for(int i = 0; i < n; i += 2){
                if((s[i] - '0') % 2) f = true;
            }
            if(f) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else{
            bool f = false;
            for(int i = 1; i < n; i += 2){
                if(!((s[i] - '0') % 2)) f = true;
            }
            if(f) cout << 2 << endl;
            else cout << 1 << endl;
        }
    }
}