#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int first[2100];
    int last[2100];
    for (int a = 0; a < 2100; a++)
    {
        first[a] = -1;
        last[a] = -1;
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            char temp;
            cin >> temp;
            if (temp == 'W')
            {
                if (first[a] == -1)
                    first[a] = b;
                last[a] = b;
            }
        }
    }
    for (int a = 1; a < n; a+=2)
        swap (first[a], last[a]);
    int prev = 0;
    int total = 0;
    int final = 0;
    for (int a = 0; a < n; a++)
    {
        if (first[a] == -1)
            continue;
        final = a;
        //if (prev != -1)
            total += abs (first[a] - prev);
        total += abs (last[a] - first[a]);
        prev = last[a];
    }
        cout << total + final << "\n";
    //system ("Pause");
    return 0;
}