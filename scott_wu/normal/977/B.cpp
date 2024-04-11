#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
char c[110];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i];

    int xm = 0, ym = 0, cm = -1;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
        {
            int ncount = 0;
            for (int k = 0; k + 1 < N; k++)
                if (c[k] - 'A' == i && c[k+1] - 'A' == j)
                    ncount++;
            if (ncount > cm)
                cm = ncount, xm = i, ym = j;
        }
    cout << (char) (xm + 'A') << (char) (ym + 'A') << "\n";
}