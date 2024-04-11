#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

string str[100];

int main()
{
    str[0] = "zero";
    str[1] = "one";
    str[2] = "two";
    str[3] = "three";
    str[4] = "four";
    str[5] = "five";
    str[6] = "six";
    str[7] = "seven";
    str[8] = "eight";
    str[9] = "nine";
    str[10] = "ten";
    str[11] = "eleven";
    str[12] = "twelve";
    str[13] = "thirteen";
    str[14] = "fourteen";
    str[15] = "fifteen";
    str[16] = "sixteen";
    str[17] = "seventeen";
    str[18] = "eighteen";
    str[19] = "nineteen";
    str[20] = "twenty";
    str[30] = "thirty";
    str[40] = "forty";
    str[50] = "fifty";
    str[60] = "sixty";
    str[70] = "seventy";
    str[80] = "eighty";
    str[90] = "ninety";
    int s;
    while (~scanf("%d", &s))
    {
        if (s < 10)
        {
            cout << str[s] << endl;
        }
        else if (s < 20)
        {
            cout << str[s] << endl;
        }
        else if (s % 10 == 0)
        {
            cout << str[s] << endl;
        }
        else
        {
            int a = s - s % 10;
            int b = s % 10;
            cout << str[a] << "-" << str[b] << endl;
        }
    }
    return 0;
}