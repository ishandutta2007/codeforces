#include <iostream>

using namespace std;

int main()
{
    string s, k = "";
    cin >> s;
    int i = 0;
    while (s[i] != '.')
    {
      i++;
      k += s[i - 1];
    }
    if (s[i - 1] == '9')
      cout << "GOTO Vasilisa.";
    else
      if (s[i + 1] < '5')
        cout << k;
      else
      {
        k[i - 1]++;
        cout << k;
      }
    return 0;
}