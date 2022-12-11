#include <iostream>
#include <string>

using namespace std;

int main()
{
    int ml = 0, k;
    string s;
    cin >> s;
    int l = s.length();
    for (int i = 0; i < l; i++)
      for (int j = i + 1; j < l; j++)
      {
        k = 0;
        while (j + k < l && s[i + k] == s[j + k])
          k++;
        if (k > ml)
          ml = k;
      }
    cout << ml;
}