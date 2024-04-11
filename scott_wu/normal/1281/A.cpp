#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    string s;
    cin >> s;
    char c = s[s.length() - 2];
    if (c == 'p') cout << "FILIPINO\n";
    else if (c == 's') cout << "JAPANESE\n";
    else cout << "KOREAN\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}