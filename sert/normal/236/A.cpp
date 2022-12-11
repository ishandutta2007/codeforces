#include <iostream>
#include <string>

using namespace std;

bool u[40];
int ans = 0;
string s;

int main()
{
    cin >> s;
    for(int i = 0; i < s.length(); i++)
      if (!u[s[i] - 'a'])
      {
        ans++;
        u[s[i] - 'a'] = true;
      }
    if (ans % 2 == 1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!" ;
    return 0;
}