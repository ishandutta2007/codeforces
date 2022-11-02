#include <bits/stdc++.h>
#include <iostream>
#define set multiset
using namespace std;

#define int long long

signed main()
{
    int n, k;

    cin >> n >> k;

    int mas[n];

    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }

    string s;

    cin >> s;

    int ans = mas[0], counter = 1;

    set<int> set;
    set.insert(mas[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            if (counter == k)
            {
                if (mas[i] > *set.begin())
                {
                    ans += mas[i] - *set.begin();
                    set.erase(set.begin());
                    set.insert(mas[i]);
                }
            }
            else
            {
                ans += mas[i];

                set.insert(mas[i]);

                counter++;
            }
        }
        else
        {
            counter = 1;
            ans += mas[i];

            set.clear();
            set.insert(mas[i]);
        }
    }

    cout << ans << endl;

    return 0;
}