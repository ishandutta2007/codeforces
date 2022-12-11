#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, k;
    int d = 'A' - 'a';
    int m = 0, b = 0;
    cin >> s >> k;
    if (s.length() != k.length())
    {
      cout << "NO";
      return 0;
    }
    for (int i = 0; i < s.length(); i++)
      if (s[i] != k[s.length() - i - 1])
      {
        cout << "NO";
        return 0;
      }

    cout << "YES";
    return 0;
}