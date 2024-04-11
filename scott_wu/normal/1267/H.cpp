#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 8600;
 
int N;
int ord[MAXN];
int res[MAXN];
set <int> locs;

vector <int> vals;

void roll (int K)
{
    locs.clear();
    locs.insert(-MAXN);
    locs.insert(MAXN);
    for (int x : vals)
    {
        locs.insert(x);
        res[x] = 0;
    }
 
    vector <int> vals_remain;
    for (int cur : vals)
    {
        locs.erase(cur);
        if (res[cur] == 0)
        {
            auto it = locs.lower_bound(cur);
            auto nit = it;
            nit--;

            if (*it < N)
                res[*it] = -1;
            if (*nit >= 0)
                res[*nit] = -1;
            res[cur] = K;
        }
        else
        {
            vals_remain.push_back(cur);
        }
    }
    vals = vals_remain;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ord[i];
        ord[i]--;

        vals.push_back(ord[i]);
    }

    reverse (vals.begin(), vals.end());

    int cc = 1;
    while (vals.size() && cc <= 22)
    {
        roll (cc);
        cc++;
    }
 
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}