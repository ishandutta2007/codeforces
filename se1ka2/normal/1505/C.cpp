#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    bool f = true;
    for(int i = 2; i < n; i++){
        if(s[i] - 'A' != (s[i - 2] - 'A' + s[i - 1] - 'A') % 26) f = false;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}