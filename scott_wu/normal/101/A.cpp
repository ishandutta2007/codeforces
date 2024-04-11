#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    int num[30]; //num of each char in string
    bool use[30];
    for (int a = 0; a < 30; a++)
    {
        num[a] = 0;
        use[a] = true;
    }
    for (int a = 0; a < n; a++)
        num[s[a] - 'a']++;
    int count = 0;
    while (count <= k)
    {
        int min = 1000000, loc = -1;
        for (int a = 0; a < 26; a++)
            if (num[a] < min && use[a])
            {
                min = num[a];
                loc = a;
            }
        if (count + min <= k)
        {
            count += min;
            use[loc] = false;
            if (count == k)
                break;
        }
        else
            break;
    }
    int ans = 0;
    for (int a = 0; a < 26; a++)
        if (use[a] && (num[a] > 0))
            ans++;
    cout << ans << "\n";
    for (int a = 0; a < n; a++)
        if (use[s[a] - 'a'])
            cout << s[a];
    cout << "\n";
    return 0;
}