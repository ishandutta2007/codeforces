#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdio.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

//#define int long long

string s;
void read()
{
    cin >> s;
}
char d[5][20];
void run()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            d[i][j] = '1';
        }
    }

    int n = s.size();
    int x = n / 20;

    if (n % 20 != 0)
        x++;
    int y = n / x;
    if (n % x != 0)
        y++;

    if (x*y == n)
    {
        for (int i = 0; i < n; i++)
        {
            d[i / y][i % y] = s[i];
        }
    } 
    else
    {
        int z = n % x;
        for (int i = 0; i < y * z; i++)
        {
            d[i / y][i % y] = s[i];
        }
        y--;
        for (int i = (y+1) * z; i < n; i++)
        {
            d[z + (i - (y+1) * z) / y][(i - (y+1) * z) % y] = s[i];
        }
        y++;
    }

    cout << x << " " << y << endl;;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            bool flag = false;
            for (auto k : s)
            {
                if (d[i][j] == k)
                    flag = true;
            }
            if (flag)
                cout << d[i][j];
            else
                cout << "*";
        }
        cout << endl;
    }
}

void write()
{

}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}