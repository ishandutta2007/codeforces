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
        int l = 0, r = n - 1;
        bool f = true;
        for(int i = n - 1; i >= 0; i--){
            if(s[l] == char('a' + i)) l++;
            else if(s[r] == char('a' + i)) r--;
            else f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}