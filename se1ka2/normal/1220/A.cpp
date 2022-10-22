#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'z') zero++;
        if(s[i] == 'n') one++;
    }
    for(int i = 0; i < one; i++) cout << "1 ";
    for(int i = 0; i < zero; i++) cout << "0 ";
    cout << endl;
}