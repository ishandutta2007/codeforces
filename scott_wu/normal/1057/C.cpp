#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, S, K;
int arr[55];
string color;
map <pair <int, int>, int> mm;

int figure (int cloc, int nleft)
{
    if (nleft <= 0) return 0;
    if (mm.find(make_pair(cloc, nleft)) != mm.end())
        return mm[make_pair(cloc, nleft)];

    int ans = 1e9;
    for (int i = 0; i < N; i++)
        if (color[i] != color[cloc] && arr[i] > arr[cloc])
            ans = min (ans, figure (i, nleft - arr[i]) + abs (i - cloc));
    mm[make_pair(cloc, nleft)] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> S >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> color;
    S--;

    int ans = 1e9;
    for (int i = 0; i < N; i++)
    {
        ans = min (ans, abs (S - i) + figure (i, K - arr[i]));
    }
    if (ans > 1e8)
        cout << "-1\n";
    else
        cout << ans << "\n";
}