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
        int b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'B') b++;
        }
        if(b * 2 == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}