#include <iostream>
#include <string>

using namespace std;

int N;
string S;
int loc[26];

int main()
{
cin >> N >> S;
for (int i = 0; i < 26; i++)
loc[i] = -1;

for (int i = S.length() - 1; i >= 0; i--)
loc[S[i]-'a'] = i;

int cnt = 0;
for (int i = 0; i < 26; i++)
if (loc[i] != -1)
cnt++;

if (cnt < N) { cout << "NO\n"; return 0;}

cout << "YES";
for (int i = 0; i < S.length(); i++)
{
for (int j = 0; j < 26; j++)
if (loc[j] == i && N)
{
N--;
cout << "\n";
}
cout << S[i];
}
return 0;
}