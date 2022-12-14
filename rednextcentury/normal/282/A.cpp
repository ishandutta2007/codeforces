#include <cstdio>
# include <iostream>
# include <string>
# include <set>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdlib>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '+') ans++;
            if (s[j] == '-') ans--;
        }
    }
    cout << ans / 2 << endl;
}