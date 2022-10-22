#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    int q = 0;
    for(int i = 0; i < n / 2; i++){
        if(s[i] == '?') q++;
        else l += s[i] - '0';
    }
    for(int i = n / 2; i < n; i++){
        if(s[i] == '?') q--;
        else r += s[i] - '0';
    }
    if(q / 2 * 9 == r - l) cout << "Bicarp" << endl;
    else cout << "Monocarp" << endl;
}