#include <iostream>

using namespace std;

int main()
{
    long long a[1000], n, i, k = 0, now, wana, h;
    cin >> n;
    for (i = 1; i < n; i++)
    {
        cin >> h;
        k = k + h;
        a[i + 1] = k;
    }
    cin >> now >> wana;
    //for (i = 1; i < n; i++) cout << a[i] << " @ ";
    cout << a[wana] - a[now];
    return 0;
}