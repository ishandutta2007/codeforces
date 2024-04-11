#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAXN = 20100;
const int INF = (int) 1e9;

int n;
int num[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    int best = -INF;
    for (int i = 1; i <= n; i++)
        if (n % i == 0 && (n / i >= 3))
        {
            for (int j = 0; j < i; j++)
            {
                int sum = 0;
                for (int k = j; k < n; k+=i)
                    sum += num[k];
                if (sum > best) best = sum;
            }
        }
    cout << best << "\n";
    //system ("Pause");
    return 0;
}