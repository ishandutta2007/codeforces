#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

string s;

bool is_char(char c)
{
    if (c - 'a' >= 0 && c - 'z' <= 0) return true;
    if (c - 'A' >= 0 && c - 'Z' <= 0) return true;
    if (c - '0' >= 0 && c - '9' <= 0) return true;
    if (c == '_') return true;
    return false;
}

bool is_username(int l, int r)
{
    for (int i = l; i <= r; i ++)
        if (!is_char(s[i]))
            return false;

    if (r - l + 1 < 1 || r - l + 1 > 16) return false;
    return true;
}

bool is_hostname(int l, int r)
{
    if (r - l + 1 < 1 || r - l + 1 > 32) return false;
    for (int i = l; i <= r; i ++)
        if (s[i] == '.')
            return is_username(l, i - 1) && is_hostname(i + 1, r);
    return is_username(l, r);
}

bool is_resource(int l, int r)
{
    return is_username(l, r);
}

bool is_good(int l, int r)
{
    bool good = false;
    for (int i = l; i <= r; i ++)
        if (s[i] == '@')
            good |= is_username(l, i - 1) && is_hostname(i + 1, r);

    for (int i = l; i <= r; i ++)
        for (int j = i + 1; j <= r; j ++)
            if (s[i] == '@' && s[j] == '/')
                good |= is_username(l, i - 1) && is_hostname(i + 1, j - 1) && is_resource(j + 1, r);
    return good;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;

    if (is_good(0, s.size() - 1))
        printf("YES\n"); else
        printf("NO\n");

    return 0;
}