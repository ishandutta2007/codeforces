#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s == "0") cout << s << endl;
    else{
        int z = 0;
        for(int i = 0; i < n; i++) if(s[i] == '0') z++;
        cout << "1";
        for(int i = 0; i < z; i++) cout << "0";
        cout << endl;
    }
}