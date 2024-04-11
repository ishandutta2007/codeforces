#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n;
char s[50];
int t[200];

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i ++)
    {
        gets(s);
        int a, b;
        char c;
        sscanf(s, "[%d:%d %c]", &a, &b, &c);
        if (c == 'a')
        {
            if (a == 12) t[i] = b; else
                t[i] = a * 60 + b;
        } else
        {
            if (a == 12) t[i] = 12 * 60 + b; else
                t[i] = 12 * 60 + a * 60 + b;
        }
    }

    int cur = 1;
	int res = 1;
    for (int i = 2; i <= n; i ++)
        if (t[i] > t[i - 1]) cur = 1; else
            if (t[i] == t[i - 1])
            {
				if (cur == 10)
				{
					cur = 1;
					res ++;
				} else
					cur ++;
            } else res ++, cur = 1;
    printf("%d\n", res);
    return 0;
}