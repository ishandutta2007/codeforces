#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

char a[10][10];
char b[10][10];

int main()
{
    for (int i = 0; i < 8; i ++)
        cin >> a[i];

    int res = 100;

    for (int i = 0; i < 256; i ++)
        for (int j = 0; j < 256; j ++)
        {
            for (int k = 0; k < 8; k ++)
                for (int l = 0; l < 8; l ++)
                    b[k][l] = 'W';

            int cur = 0;
            for (int k = 0; k < 8; k ++)
                if ((i & (1 << k)) != 0)
                {
                    cur ++;
                    for (int l = 0; l < 8; l ++)
                        b[k][l] = 'B';
                }
            for (int k = 0; k < 8; k ++)
                if ((j & (1 << k)) != 0)
                {
                    cur ++;
                    for (int l = 0; l < 8; l ++)
                        b[l][k] = 'B';
                }

            bool good = true;
            for (int k = 0; k < 8; k ++)
                for (int l = 0; l < 8; l ++)
                    if (b[k][l] != a[k][l]) good = false;
            if (good && cur < res) res = cur;
        }
    cout << res << endl;
    return 0;
}