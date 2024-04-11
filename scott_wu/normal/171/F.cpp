#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

bool prime (int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int reverse (int x)
{
    vector <int> dig; dig.clear();
    while (x > 0)
    {
        dig.push_back (x % 10);
        x /= 10;
    }
    int ans = 0;
    for (int i = 0; i < dig.size(); i++)
        ans = 10 * ans + dig[i];
    return ans;
}

int main()
{
    int d; cin >> d;
    int num = 0;
    for (int i = 11; i <= 1000000; i+=2)
    {
        if (i != reverse(i) && prime (i) && prime (reverse (i)))
            num++;
        if (num == d)
        {
            cout << i << "\n";
            break;
        }
    }
    //system ("Pause");
    return 0;
}