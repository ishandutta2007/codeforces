#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

ofstream fout ("weigh.out");
ifstream fin ("weigh.in");

int num (int a, int b, int c, int d)
{
    return a * 1000 + b * 100 + c * 10 + d;
}

int main()
{
    int n;
    cin >> n;
    int digit[1100][4];
    int temp;
    for (int a = 0; a < n; a++)
    {
        cin >> temp;
        digit[a][3] = temp % 10;
        temp /= 10;
        digit[a][2] = temp % 10;
        temp /= 10;
        digit[a][1] = temp % 10;
        temp /= 10;
        digit[a][0] = temp % 10;
        temp /= 10;
    }
    int max = 1000;
    bool check;
    int temp2;
    int ans[1100];
    for (int a = 0; a < n; a++)
    {
        int min = 2012;
        check = false;
        for (int c = 1; c <= 2; c++)
        {
            temp2 = c * 1000 + digit[a][1] * 100 + digit[a][2] * 10 + digit[a][3];
            if (temp2 >= max && temp2 <= 2011 && temp2 < min)
            {
               min = temp2;
               check = true;
            }
        }
        for (int c = 0; c <= 9; c++)
        {
            int temp2 = digit[a][0] * 1000 + c * 100 + digit[a][2] * 10 + digit[a][3];
            if (temp2 >= max && temp2 <= 2011 && temp2 < min)
            {
               min = temp2;
               check = true;
            }
        }
        for (int c = 0; c <= 9; c++)
        {
            int temp2 = digit[a][0] * 1000 + digit[a][1] * 100 + c * 10 + digit[a][3];
            if (temp2 >= max && temp2 <= 2011 && temp2 < min)
            {
               min = temp2;
               check = true;
            }
        }
        for (int c = 0; c <= 9; c++)
        {
            int temp2 = digit[a][0] * 1000 + digit[a][1] * 100 + digit[a][2] * 10 + c;
            if (temp2 >= max && temp2 <= 2011 && temp2 < min)
            {
               min = temp2;
               check = true;
            }
        }
        if (check)
        {
           ans[a] = min;
           max = min;
           continue;
        }
        cout << "No solution\n";
        return 0;
    }
    for (int a = 0; a < n; a++)
        cout << ans[a] << "\n";
    return 0;
}