#include <iostream>
#include <string>

using namespace std;

string c = "CODEFORCES";

int main()
{
string s;
cin >> s;
int lo = 0, hi = s.length() - 1;
while (s[lo] == c[lo])lo++;
while (s[hi] == c[10-(s.length()-hi)])hi--;

cout << ((lo+s.length()-1-hi>=10) ? "YES" : "NO") << "\n";
return 0;
}