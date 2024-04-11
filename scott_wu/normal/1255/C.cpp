#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int nc[MAXN];
map <pair <int, int>, vector <int> > mm;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 2; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        nc[x]++;
        nc[y]++;
        nc[z]++;

        mm[make_pair (x, y)].push_back(z);
        mm[make_pair (x, z)].push_back(y);
        mm[make_pair (y, z)].push_back(x);
        mm[make_pair (y, x)].push_back(z);
        mm[make_pair (z, x)].push_back(y);
        mm[make_pair (z, y)].push_back(x);
    }

    int b = 0;
    for (int i = 1; i <= N; i++)
        if (nc[i] == 1) b = i;

    int b2 = 0;
    for (int i = 1; i <= N; i++)
    {
        if (nc[i] == 2 && mm.find(make_pair (b, i)) != mm.end())
            b2 = i;
    }

    cout << b << " " << b2;
    for (int i = 3; i <= N; i++)
    {
        vector <int> cands = mm[make_pair (b, b2)];
        int ans = cands[0];
        if (nc[ans] == -1) ans = cands[1];
        cout << " " << ans;
        nc[b] = -1;
        b = b2;
        b2 = ans;
    }
    cout << "\n";
}