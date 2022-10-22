#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n, na=0;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == 'a')
            na++;
    na = na * 2 - 1;
    if (n < na)
        na = n;
    cout << na << endl;
    return 0;
}