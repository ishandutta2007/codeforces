#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 400100;

int Q;
map <int, int> mres;
int ntype;
map <int, int> mtype;
vector <int> tlist[MAXN];

void cput (int x)
{
    if (mtype.find(x) != mtype.end()) return;
    mtype[x] = ntype;
    tlist[ntype].push_back(x);
    mres[x] = 0;

    ntype++;
}

int cf (int l, int r)
{
    if (mtype.find(l) == mtype.end() || mtype.find(r) == mtype.end()) return -1;
    if (mtype[l] != mtype[r]) return -1;
    return mres[l] ^ mres[r];
}

void merge (int l, int r, int x)
{
    // assume diff types
    x ^= mres[l] ^ mres[r];
    int ltype = mtype[l], rtype = mtype[r];
    if (tlist[ltype].size() < tlist[rtype].size())
        swap (ltype, rtype);

    for (int c : tlist[rtype])
    {
        //cout << c << " " << mres[c] << " " << x << "\n";
        mres[c] = mres[c] ^ x;
        mtype[c] = ltype;
        tlist[ltype].push_back(c);
    }
    tlist[rtype].clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> Q;
    int clast = 0;
    for (int i = 0; i < Q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l ^= clast;
        r ^= clast;
        if (l > r) swap (l, r);
        r++;

        //cout << l << " " << r << endl;

        if (t == 1)
        {
            int x; cin >> x;
            x ^= clast;

            cput (l);
            cput (r);
            if (cf (l, r) != -1)
                continue;
            merge (l, r, x);
        }
        else
        {
            cput (l);
            cput (r);
            int res = cf (l, r);
            cout << res << "\n";

            clast = res;
            if (res == -1)
                clast = 1;
            // change clast
        }
    }
}