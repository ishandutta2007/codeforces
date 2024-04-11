#include <iostream>
#include <stdio.h>

using namespace std;

char str[150];
int nchar;

int main()
{
    nchar = 0;
    while (true)
    {
        str[nchar] = getchar ();
        if (str[nchar] == '\n') break;
        nchar++;
    }
    int last = 0;
    for (int i = 0; i < nchar; i++)
    {
        int temp = 0;
        if (i > 0)
        for (int j = 0; j < 8; j++)
            if ((int) (str[i-1] >> j) & 1)
                temp += 1 << (7 - j);
        //cout << (int) temp << " " << (int) str[i] << "\n";;
        last = temp;
        temp = 0;
        for (int j = 0; j < 8; j++)
            if ((int) (str[i] >> j) & 1)
                temp += 1 << (7 - j);
        last = (last - temp + 256) % 256;
        cout << (int) last << "\n";
    }
    //system ("Pause");
    return 0;
}