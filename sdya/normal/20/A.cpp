#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

char s[500];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets(s);
    int n = strlen(s);
    string res = "";
    for (int i = 0; i < n; i ++)
        if (s[i] != '/') res += s[i]; else
        if ((s[i] == '/' && i == 0) || (s[i] == '/' && s[i - 1] != '/'))
            res += '/';
    if (res == "/") cout << res << endl; else
        if (res[res.size() - 1] != '/') cout << res << endl; else
        for (int i = 0; i < (int)(res.size()) - 1; i ++)
            cout << res[i];
    return 0;
}