#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

pair <ll, int> num[MAXN];
int N;
ll D, A, B;

int main()
{
    cin >> N >> D >> A >> B;
    for (int i = 0; i < N; i++)
    {
        ll x, y; cin >> x >> y;
        num[i].first = x * A + y * B;
        num[i].second = i;
    }
    sort (num, num + N);
    ll tot = 0, end = -1;
    for (int i = 0; i < N; i++)
    {
        if (tot + num[i].first <= D)
            tot += num[i].first;
        else
        {
            end = i;
            break;
        }
    }
    if (end == -1) end = N;
    cout << end << "\n";
    for (int i = 0; i < end; i++)
    {
        if (i > 0) cout << " ";
        cout << num[i].second + 1;
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}