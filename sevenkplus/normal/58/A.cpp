#include <iostream>
#include <string>

using namespace std;

string s;
const string hello = "hello";

int main()
{
    getline(cin, s);
    int j = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == hello[j]) 
            j++;
        if (j == 5){
            flag = true;
            break;
        }
    }
    if (flag) 
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}