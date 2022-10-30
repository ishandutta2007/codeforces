#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

char c[5][5];

bool x_win()
{
    if (c[0][0] == 'X' && c[0][1] == 'X' && c[0][2] == 'X') return true;
    if (c[1][0] == 'X' && c[1][1] == 'X' && c[1][2] == 'X') return true;
    if (c[2][0] == 'X' && c[2][1] == 'X' && c[2][2] == 'X') return true;

    if (c[0][0] == 'X' && c[1][0] == 'X' && c[2][0] == 'X') return true;
    if (c[0][1] == 'X' && c[1][1] == 'X' && c[2][1] == 'X') return true;
    if (c[0][2] == 'X' && c[1][2] == 'X' && c[2][2] == 'X') return true;

    if (c[0][0] == 'X' && c[1][1] == 'X' && c[2][2] == 'X') return true;
    if (c[0][2] == 'X' && c[1][1] == 'X' && c[2][0] == 'X') return true;
    return false;
}

bool o_win()
{
    if (c[0][0] == '0' && c[0][1] == '0' && c[0][2] == '0') return true;
    if (c[1][0] == '0' && c[1][1] == '0' && c[1][2] == '0') return true;
    if (c[2][0] == '0' && c[2][1] == '0' && c[2][2] == '0') return true;

    if (c[0][0] == '0' && c[1][0] == '0' && c[2][0] == '0') return true;
    if (c[0][1] == '0' && c[1][1] == '0' && c[2][1] == '0') return true;
    if (c[0][2] == '0' && c[1][2] == '0' && c[2][2] == '0') return true;

    if (c[0][0] == '0' && c[1][1] == '0' && c[2][2] == '0') return true;
    if (c[0][2] == '0' && c[1][1] == '0' && c[2][0] == '0') return true;
    return false;
}

int count_X()
{
    int res = 0;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            if (c[i][j] == 'X') res ++;
    return res;
}

int count_O()
{
    int res = 0;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            if (c[i][j] == '0') res ++;
    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets(c[0]);
    gets(c[1]);
    gets(c[2]);

    if (count_X() != count_O() + 1 && count_X() != count_O())
    {
        printf("illegal\n");
        return 0;
    }

    if (x_win() && o_win())
    {
        printf("illegal\n");
        return 0;
    }

    if (x_win())
    {
        if (count_X() != count_O() + 1)
        {
            printf("illegal\n");
            return 0;
        }
        printf("the first player won\n");
        return 0;
    }

    if (o_win())
    {
        if (count_X() != count_O())
        {
            printf("illegal\n");
            return 0;
        }
        printf("the second player won\n");
        return 0;
    }

    
    if (count_X() + count_O() == 9)
    {
        printf("draw\n");
        return 0;
    }

    if (count_X() == count_O() + 1)
    {
        printf("second\n");
        return 0;
    }

    if (count_X() == count_O())
    {
        printf("first\n");
        return 0;
    }
    
    return 0;
}