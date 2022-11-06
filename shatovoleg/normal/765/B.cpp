#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt[26];
    for (int i = 0; i < 26; ++i)
        cnt[i] = 0;
    for (auto x : s)
    {
        ++cnt[x - 'a'];
        if (x == 'a')
            continue;
        if (cnt[x - 'a' - 1] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}