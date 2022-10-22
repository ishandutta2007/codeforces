#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int c = 0;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] == 'B') c--;
            else c++;
            if(c < 0) f = false;
        }
        if(s[n - 1] == 'A') f = false;
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}