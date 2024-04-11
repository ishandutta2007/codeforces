#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev[100100], best[100100], sg[100100], sgtotal[100100];
    for (int a = 0; a < 100100; a++)
    {
        prev[a] = -1;
        sg[a] = 0;
        sgtotal[a] = 0;
        best[a] = 10000000;
    }
    for (int a = 1; a <= n; a++)
    {
        for (int b = 2; b * b < a * 2; b++)
        {
            if (2 * a % b != 0)
                continue;
            int start = a * 2 / b - b + 1;
            if (start % 2 == 1)
                continue;
            start /= 2;
            if (sgtotal[start-1] == sgtotal[start+b-1])
                best[a] = min (best[a], b);
            prev[sgtotal[start-1]^sgtotal[start+b-1]] = a;
        }
        while (prev[sg[a]] == a)
            sg[a]++;
        sgtotal[a] = sgtotal[a-1]^sg[a];
    }
    if (sg[n])
        cout << best[n] << "\n";
    else
        cout << "-1\n";
    return 0;
}