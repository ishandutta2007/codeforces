#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    vector<char> c;
    int i1=0, i0=0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        c.push_back(s[i]);
        if (s[i] == '1')
            i1++;
        else
            i0++;
    }
    if (i1 != i0) {
        cout << "1" << endl << s;
        return 0;
    }
    cout << "2" << endl << c[0] << " ";
    for (int i = 1; i < n; i++)
        cout << c[i];
    return 0;
}