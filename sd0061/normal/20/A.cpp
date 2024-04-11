#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 50005
typedef long long LL;
#define fi first
#define se second
using namespace std;

void work()
{
    string s;
    getline(cin, s);

    string c = "";
    for(int i = 0 ; i < s.size() ; ++ i)
        if (s[i] == '/') {
            int j = i;
            while (j < (int)s.size() && s[j] == '/')
                j++;
            i = j - 1;
            c += "/";
        }
        else
            c += s[i];

    if (c != "/" && c[c.size() - 1] == '/')
        c.erase(c.size() - 1);

    cout << c << endl;
}

int main()
{
  //freopen("input.txt","r",stdin);
 //int _; scanf("%d",&_); while (_--)
    work();
  return 0;
}