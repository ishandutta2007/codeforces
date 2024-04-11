#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cou = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+')
            cou++;
        else if (cou > 0)
            cou--;
    }
    cout << cou << endl;
    return 0;
}