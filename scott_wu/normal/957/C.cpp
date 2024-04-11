#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const int MAXN = 100100;

int N, U;
int E[MAXN];

int main()
{
    cin >> N >> U;
    for (int i = 0; i < N; i++)
        cin >> E[i];

    int cloc = 0;
    double bval = -1;
    for (int i = 0; i < N; i++)
    {
        while (cloc < N - 1 && E[cloc+1] - E[i] <= U)
            cloc++;
        if (cloc >= i + 2)
            bval = max (bval, (E[cloc] - (double) E[i+1]) / (E[cloc] - (double) E[i]));
    }

    if (bval < 0)
    {
        cout << "-1\n";
        return 0;
    }

    cout << fixed << setprecision(9);
    cout << bval << "\n";
}