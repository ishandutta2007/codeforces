#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long init;
    long long stop; //all>=stop == X
    if (k == 1)
    {
        init = n - 1;
        stop = n;
    }
    else
    {
        if (k == 0)
        {
            init = n;
            stop = n + 1;
        }
        else
        {
        if (n % 2 == 0)
        {
            if (n >= 2 * k)
            {
                init = n - 2 * k + 1;
                stop = n + 1;
            }
            else
            {
                init = 1;
                stop = 2 * (n - k) + 1;
            }
        }
        else
        {
            n--;
            k--;
            if (n >= 2 * k)
            {
                init = n - 2 * k + 1;
                stop = n + 1;
            }
            else
            {
                init = 1;
                stop = 2 * (n - k) + 1;
            }
            n++;
            k++;
        }
        }
    }
    int p;
    long long x;
    cin >> p;
    for (int a = 0; a < p; a++)
    {
        cin >> x;
        if (x >= stop)
        {
            cout << "X";
            continue;
        }
        if (x <= init)
        {
            cout << ".";
            continue;
        }
        if ((x - init) % 2 == 1)
            cout << "X";
        else
            cout << ".";
    }
    cout << "\n";
    return 0;
}