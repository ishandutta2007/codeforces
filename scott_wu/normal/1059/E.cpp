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
const int MAXN = 100100;

int N, L;
ll S;

vector <ll> v;
vector <int> edge[MAXN];
ll mup[MAXN];
ll w[MAXN];
int ans;

void flood (int cloc)
{
    ll mbest = 0;
    for (int neigh : edge[cloc])
    {
        v.push_back(v.back()+w[neigh]);
        flood (neigh);
        v.pop_back();
        mbest = max (mbest, mup[neigh]);
    }

    if (mbest >= w[cloc])
    {
        mup[cloc] = mbest - w[cloc];
    }
    else
    {
        ans++;
        mup[cloc] = min (S, v.back() - v[(int) v.size() - L - 1]);
        mup[cloc] -= w[cloc];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> L >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i < N; i++)
    {
        int x; cin >> x;
        x--;
        edge[x].push_back(i);
    }

    bool bad = false;
    for (int i = 0; i < N; i++)
        if (w[i] > S)
            bad = true;
    if (bad)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i <= L; i++)
        v.push_back(0);
    v.push_back(w[0]);
    flood (0);

    cout << ans << "\n";
}