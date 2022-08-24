#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long x; cin >> x;
        long long t = sqrt (x) + 0.1;
        if (t * t == x && x > 1)
        {
            bool p = true;
            if (t > 2 && x % 2 == 0)
                p = false;
            for (int j = 3; j * j <= t; j+=2)
                if (t % j == 0)
                {
                    p = false;
                    break;
                }
            if (p) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
}