#include <bits/stdc++.h>

using namespace std;

int get_dist(char a, char b)
{
    return min(abs(a - b), 26 - abs(a - b));
}

int main()
{
    string a;
    cin >> a;
    char prev = 'a';
    int ans = 0;
    for (auto x : a)
    {
        ans += get_dist(x, prev);
        prev = x;
    }
    cout << ans << endl;
}