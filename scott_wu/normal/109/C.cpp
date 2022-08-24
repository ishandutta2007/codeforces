#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

vector <int> edge[MAXN];
int color[MAXN];
int nfound;

bool lucky (int x)
{
    while (x > 0)
    {
        if ((x % 10 != 4) && (x % 10 != 7))
            return false;
        x /= 10;
    }
    return true;
}

void flood (int cur)
{
    if (color[cur] == 0)
        return;
    color[cur] = 0;
    nfound++;
    for (int i = 0; i < edge[cur].size(); i++)
        flood (edge[cur][i]);
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int temp, temp2, temp3;
        cin >> temp >> temp2 >> temp3;
        temp--; temp2--;
        if (!lucky (temp3))
        {
            edge[temp].push_back (temp2);
            edge[temp2].push_back (temp);
        }
    }
    for (int i = 0; i < MAXN; i++)
        color[i] = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            nfound = 0;
            flood (i);
            ans += (ll) nfound * (ll) (n - nfound) * (ll) (n - nfound - 1);
        }
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}