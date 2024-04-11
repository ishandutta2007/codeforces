#include <iostream>
#include <string>

using namespace std;

int n, x, ans;
string s;
char lst;

int main()
{
    cin >> n;
    cin >> s;
    lst = s[0];
    for (int i = 1; i < s.length(); i++)
        if (s[i] == lst)
            ans++;
        else
            lst = s[i];
    cout << ans;
    return 0;
}