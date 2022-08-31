#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int P, Y;
int NP;

int main()
{
    cin >> P >> Y;
    int NP = P;
    if (P >= 40000)
        NP = 40000;



    while (Y > P)
    {
        bool found = false;
        for (int i = 2; i <= NP; i++)
        {
            if (Y % i == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
            break;
        Y--;
    }
    if (Y <= P)
    {
        cout << "-1\n";
    }
    else
    {
        cout << Y << "\n";
    }
}