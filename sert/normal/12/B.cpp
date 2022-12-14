#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char a[20];
    string s;
    cin >> s;
    //cout << s << endl;
    //cout << s[0] << endl;
    fr(i, s.length() - 1)
      fr(j, s.length() - i - 1)
        if(s[j] > s[j + 1])
          swap(s[j], s[j + 1]);
    //cout << s << "|" << endl;
    int i = 0;
    while (i + 1 < s.length() && s[i] == '0') i++;
    swap(s[0], s[i]);
    //cout << s << endl;
    string k; cin >> k;
   // cout << s << endl;
    if(k == s) cout << "OK"; else cout << "WRONG_ANSWER";
    return 0;
}