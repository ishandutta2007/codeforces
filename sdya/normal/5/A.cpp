#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <set>

using namespace std;

set < string > S;
char c[200];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int res = 0;
    while (gets(c))
    {
        string s = "";
        if (c[0] == '+')
        {
            int n = strlen(c);
            for (int i = 1; i < n; i ++)
                s += c[i];
            S.insert(s);
        } else
        if (c[0] == '-')
        {
            int n = strlen(c);
            for (int i = 1; i < n; i ++)
                s += c[i];
            S.erase(s);
        } else
        {
            int n = strlen(c), m = 0;
            for (int i = 1; i < n; i ++)
                if (c[i] != ':')
                {
                    s += c[i];
                } else 
                {
                    m = n - i - 1;
                    break;
                }
                res += (int)(S.size()) * m;
        }
    }
    printf("%d\n", res);
    return 0;
}