#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[1002];
        for(int i = 0; i < n; i++) cin >> s[i];
        if(m % 2 || s[0][1] == s[1][0]){
            cout << "YES" << endl;
            for(int i = 0; i <= m; i++) cout << i % 2 + 1 << " ";
            cout << endl;
            continue;
        }
        if(n == 2){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(s[0][1] == s[1][2] && s[1][2] == s[2][0]){
            for(int i = 0; i <= m; i++) cout << i % 3 + 1 << " ";
            cout << endl;
            continue;
        }
        int l;
        if(s[0][1] == s[1][2]) l = 2;
        if(s[1][2] == s[2][0]) l = 0;
        if(s[2][0] == s[0][1]) l = 1;
        if(m % 3 == 0){
            for(int i = 0; i <= m; i++) cout << (l + 2 + i) % 3 + 1 << " ";
            cout << endl;
        }
        else if(m % 3 == 1){
            for(int i = 0; i <= m; i++) cout << (l + i) % 3 + 1 << " ";
            cout << endl;
        }
        else{
            for(int i = 0; i <= m; i++) cout << (l + i + 1) % 3 + 1 << " ";
            cout << endl;
        }
    }
}