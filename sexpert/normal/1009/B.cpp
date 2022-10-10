#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s, t = "", r = "";
   int ones = 0, n = 0;
   cin >> s;
   for(char c : s)
   {
       if(c == '0' || c == '2') t += c;
       else ones++;
   }
   while(!t.empty() && t[0] != '2')
   {
       r += '0';
       t = t.substr(1);
   }
   for(int i = 0; i < ones; i++) r += '1';
   r += t;
   cout << r;
}