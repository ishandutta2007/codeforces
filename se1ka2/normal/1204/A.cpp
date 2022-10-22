#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            cout << (n + 1) / 2 << endl;
            return 0;
        }
    }
    cout << n / 2 << endl;
}