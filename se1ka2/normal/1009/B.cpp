#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int f2;
    for(f2 = 0; f2 < n; f2++){
        if(s[f2] == '2') break;
    }
    int c1 = 0;
    for(int i = 0; i < n; i++) if(s[i] == '1') c1++;
    for(int i = 0; i < f2; i++) if(s[i] == '0') cout << 0;
    for(int i = 0; i < c1; i++) cout << 1;
    for(int i = f2; i < n; i++) if(s[i] != '1') cout << s[i] - '0';
    cout << endl;
}