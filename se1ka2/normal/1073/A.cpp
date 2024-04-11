#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] != s[i + 1]){
            cout << "YES" << endl;
            cout << s[i] << s[i + 1] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}