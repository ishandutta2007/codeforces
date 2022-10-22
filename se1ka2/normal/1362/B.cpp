#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b[1050]{0};
        int s[1050];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            b[s[i]] = true;
        }
        int m;
        for(m = 1; m < 1024; m++){
            bool f = true;
            for(int i = 0; i < n; i++){
                if(!b[s[i] ^ m]) f = false;
            }
            if(f) break;
        }
        if(m < 1024) cout << m << endl;
        else cout << -1 << endl;
    }
}