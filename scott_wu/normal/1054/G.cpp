#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, M;
string secret[MAXN];
bitset <MAXN> b[MAXN];
int edge[MAXN][MAXN];
int cdist[MAXN];
bool seen[MAXN];

void gogo()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> secret[i];

    int btot = 0;
    for (int i = 0; i < N; i++)
    {
        b[i].reset();
        for (int j = 0; j < M; j++)
            if (secret[j][i] == '1')
            {
                b[i].set(j);
                btot++;
            }
    }
    btot -= M;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            edge[i][j] = edge[j][i] = (b[i] & b[j]).count();
            //cout << i << " " << j << " " << edge[i][j] << "\n";
        }
    }

    for (int i = 0; i < N; i++)
    {
        cdist[i] = -1e9;
        seen[i] = false;
    }
    cdist[0] = 0;

    int ctot = 0;
    vector <pair <int, int> > v;
    for (int i = 0; i < N; i++)
    {
        int bloc = -1, bval = -1;
        for (int j = 0; j < N; j++)
            if (!seen[j] && cdist[j] > bval)
            {
                bval = cdist[j];
                bloc = j;
            }

        if (i)
        {
            int bsource = -1;
            for (int j = 0; j < N; j++)
                if (seen[j] && edge[j][bloc] == bval)
                    bsource = j;
            v.push_back(make_pair (bsource, bloc));
        }

        ctot += cdist[bloc];
        seen[bloc] = true;
        for (int j = 0; j < N; j++)
            if (j != bloc)
                cdist[j] = max (cdist[j], edge[bloc][j]);
    }

    if (ctot != btot)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first + 1 << " " << v[i].second + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        gogo();
}