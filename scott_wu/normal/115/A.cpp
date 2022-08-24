#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int man[2100];
    for (int a = 1; a <= n; a++)
    {
        cin >> man[a];
    }
    int best = 0;
    for (int a = 1; a <= n; a++)
    {
        int val = 1, cur = a;
        while (true)
        {
            if (man[cur] == -1)
                break;
            val++;
            cur = man[cur];
        }
        best = max (best, val);
    }
    cout << best << "\n";
    return 0;
}