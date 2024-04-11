#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int tot, n;
char* getout(char* str, int l)
{
    int j = 0, t = 0;
    char temp[32768];
    memset(temp, 0, sizeof(temp));

    while (!isalpha(str[j])) ++j;
    while (isalpha(str[j]) || isdigit(str[j])) ++j;
    while (!isalpha(str[j])) ++j;
    while (isalpha(str[j]) || isdigit(str[j])) temp[t++] = str[j++];
    temp[t] = '\0';
    if (l == 1) return temp;
    while (str[j] != '"') ++j;
    ++j;
    memset(temp, 0, sizeof(temp));
    t = 0;
    while (str[j] != '\"') temp[t++] = str[j++];
    temp[t] = '\0';
    return temp;
}
char str[32768], now[32768], stack[32768], res[32768];
int main()
{
    scanf("%d", &n);
    gets(str);
    tot = 0;
    bool begin = false, first = true;
    int nowdeep = 0;
    for (int i = 1; i <= n; ++i)
    {
        gets(str);
        int j = 0, len = strlen(str);
        while (!isalpha(str[j]) && (j < len)) ++j;
        if (j == len) continue;
        if ((str[j] == 't') && (str[j + 1] == 'h'))
        {
            begin = true;
            strcpy(now, getout(str, 1));
            continue;
        }
        if (!begin) continue;
        else
        {
            if (str[j] == 't') nowdeep++;
            else
            {
                if ((nowdeep <= 0) && (first))
                {
                    strcpy(stack, getout(str, 1));
                    strcpy(res, getout(str, 2));
                    if (!strcmp(stack, now))
                    {
                        //if ((n == 100000) && strcmp(res, "GYqJhuyoTApao")) printf("%s %s ", now, res);
                        puts(res);
                        return 0;
                    }
                    first = false;
                }
                else if (nowdeep < 0)
                {
                    nowdeep = 0;
                    strcpy(stack, getout(str, 1));
                    strcpy(res, getout(str, 2));
                    if (!strcmp(stack, now))
                    {
                        //if ((n == 100000) && strcmp(res, "GYqJhuyoTApao")) printf("%s %s ", now, res);
                        puts(res);
                        return 0;
                    }
                }
                nowdeep--;
            }
        }
    }
    puts("Unhandled Exception");
    return 0;
}