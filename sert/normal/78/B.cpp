#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string s[7];
    s[0] = 'R';
    s[1] = 'O';
    s[2] = 'Y';
    s[3] = 'G';
    s[4] = 'B';
    s[5] = 'I';
    s[6] = 'V';
    int n;
    cin >> n;
    for (int i = 0; i < n - 3; i++)
      cout << s[i % 4];
    cout << "BIV";
}