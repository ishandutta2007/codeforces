#include <iostream>
using namespace std;
    char s[20];

bool pa()
{
    for (int i = 0 ; s[i] ; ++ i)
      if (s[i] != '1' && s[i] != '4')
        return 0;
    if (s[0] != '1') return 0;
    for (int i = 0 ; s[i + 2] ; ++ i)
      if (s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '4')
        return 0;
    return 1;
}

int main()
{
    cin >> s;
    cout << (pa() ? "YES" : "NO");
}