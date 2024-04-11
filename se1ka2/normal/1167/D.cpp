#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nd = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') nd++;
        cout << nd % 2;
        if(s[i] == ')') nd--;
    }
    cout << endl;
}