#include <iostream>

using namespace std;

int n = 0;
char c[1100][1100];
char s[1100];

int l[1100];
int mx_len = 0;

int lt = true;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while (gets(s))
    {
        n ++;
        l[n] = strlen(s);
        for (int i = 0; i < l[n]; i ++)
            c[n][i] = s[i];
    }

    for (int i = 1; i <= n; i ++)
        if (l[i] > mx_len) mx_len = l[i];

    for (int i = 1; i <= mx_len + 2; i ++)
        printf("*");
    printf("\n");
    for (int i = 1; i <= n; i ++)
    {
        printf("*");
        if ((mx_len + l[i]) % 2 == 0)
        {
            for (int j = 1; j <= (mx_len - l[i]) / 2; j ++)
                printf(" ");
            printf("%s", c[i]);
            for (int j = 1; j <= (mx_len - l[i]) / 2; j ++)
                printf(" ");
        } else
        {
            if (lt)
            {
                for (int j = 1; j <= (mx_len - l[i]) / 2; j ++)
                    printf(" ");
                printf("%s", c[i]);
                for (int j = 1; j <= (mx_len - l[i]) / 2 + 1; j ++)
                    printf(" ");
                lt = false;
            } else
            {
                for (int j = 1; j <= (mx_len - l[i]) / 2 + 1; j ++)
                    printf(" ");
                printf("%s", c[i]);
                for (int j = 1; j <= (mx_len - l[i]) / 2; j ++)
                    printf(" ");
                lt = true;
            }
        }
        printf("*\n");
    }
    for (int i = 1; i <= mx_len + 2; i ++)
        printf("*");
    printf("\n");


    return 0;
}