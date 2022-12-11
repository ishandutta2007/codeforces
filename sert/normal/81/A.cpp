#include <iostream>

using namespace std;

string s, k = "@";

int main()
{
    cin >> s;
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == k[len])
        len--;
      else
      {
        len++;
        k += s[i];
        k[len] = s[i];
      }
    }
    for (int i = 1; i <= len; i++)
      cout << k[i];
}