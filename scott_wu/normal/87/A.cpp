#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int gcf (int a, int b)
{
    if (b == 0)
       return a;
    return gcf (b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a / (gcf (a, b));
    int d = b / (gcf (a, b));
    if (c - d == 1 || d - c == 1)
    {
       cout << "Equal\n";
       return 0;;
    }
    if (a > b)
       cout << "Masha\n";
    else
        cout << "Dasha\n";
    return 0;
}