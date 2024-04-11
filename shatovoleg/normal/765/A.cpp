#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, s1;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s1;
        if (s1.substr(0, 3) == s)
            ++cnt1;
        if (s1.substr(5, 3) == s)
            ++cnt2;
    }
    if (cnt1 == cnt2)
        cout << "home" << endl;
    else
        cout << "contest" << endl;
}