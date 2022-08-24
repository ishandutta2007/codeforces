#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
pair <int, ll> p[110];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].second;
        ll t = p[i].second;
        int x = 0, y = 0;
        while (t % 3 == 0)
        {
            t /= 3;
            x++;
        }
        while (t % 2 == 0)
        {
            t /= 2;
            y++;
        }
        p[i].first = (100 - x) * 100 + 100 + y;
    }
    sort (p, p + N);
    for (int i = 0; i < N; i++)
        cout << p[i].second << " ";
}