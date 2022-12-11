#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, k;
    cin >> s;
    cin >> k;
    int d = 'a' - 'A';
    for (int i = 0; i < s.length(); i++)
      if (s[i] < 'a')
        s[i] = s[i] + d;
    for (int i = 0; i < k.length(); i++)
      if (k[i] < 'a')
        k[i] = k[i] + d;
    if (s == k) cout << 0;
    if (s > k) cout << 1;
    if (s < k) cout << -1;
    return 0;
}