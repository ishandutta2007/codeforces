#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if(s[0] == s.back()) cout << -1 << endl;
        else cout << s << endl;
    }
}