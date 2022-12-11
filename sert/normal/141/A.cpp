#include <iostream>

using namespace std;

string s, k, p;
int a[30] = {0}, b[30] = {0};
bool fail = false;

int main()
{
    cin >> s >> k >> p;
    for (int i = 0; i < s.length(); i++)
      a[s[i] - 'A']++;
    for (int i = 0; i < k.length(); i++)
      a[k[i] - 'A']++;
    for (int i = 0; i < p.length(); i++)
      b[p[i] - 'A']++;
    for (int i = 0; i < 30; i++)
      if (a[i] != b[i])
        fail = true;
    if (fail)
      cout << "NO";
    else
      cout << "YES";
}