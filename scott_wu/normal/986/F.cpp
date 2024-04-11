#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXM = 100100;
const int MAXS = 4e7;
const int MAXT = 10100;
const int MAXK = 55;

int p[MAXS];
vector <int> small_primes;
map <ll, int> m;
int T;
ll N[MAXT], K[MAXT];
int nfac;
vector <ll> factors[MAXK];
ll dijk[MAXK][MAXM];
bool seen[MAXM];

void fill (ll x)
{
    ll old_x = x;
    if (m.find(x) != m.end())
        return;
    vector <ll> res;
    for (int i = 0; i < small_primes.size(); i++)
    {
        int pcur = small_primes[i];
        if (x % pcur == 0)
        {
            factors[nfac].push_back(pcur);
            while (x % pcur == 0)
                x /= pcur;
        }
        if (x == 1)
            break;
    }

    if (x > 1)
        factors[nfac].push_back(x);
    m[old_x] = nfac;
    nfac++;
}

priority_queue<pair <ll, int> > q;

void solve_fac (int cfac)
{
    if (factors[cfac].size() == 1)
        return;
    if (factors[cfac].size() == 2)
    {

        return;
    }

    int base = factors[cfac][0];
    for (int i = 0; i < base; i++)
    {
        seen[i] = 0;
        dijk[cfac][i] = 1e18;
    }
    dijk[cfac][0] = 0;
    q.push(make_pair (0, 0));

    while (!q.empty())
    {
        int cloc = q.top().second;
        q.pop();
        if (seen[cloc])
            continue;
        seen[cloc] = true;
        ll cdist = dijk[cfac][cloc];

        for (int i = 1; i < factors[cfac].size(); i++)
        {
            ll fval = factors[cfac][i];
            int neigh = (fval + cloc) % base;
            if (dijk[cfac][neigh] > cdist + fval)
            {
                dijk[cfac][neigh] = cdist + fval;
                q.push(make_pair(-dijk[cfac][neigh], neigh));
            }
        }
    }
}

ll cpow (ll x, ll y, ll p)
{
    x %= p;
    if (y == 0) return 1;
    if (y == 1) return x;
    ll v = cpow (x, y / 2, p);
    v = (v * v) % p;
    if (y % 2 == 1)
        v = (v * x) % p;
    return v;
}

bool works (ll n, int cfac)
{
    //cout << cfac << " " << factors[cfac].size() << "\n";
    if (factors[cfac].size() == 1)
    {
        return ((n % factors[cfac][0]) == 0);
    }
    else if (factors[cfac].size() == 2)
    {
        ll l = factors[cfac][0], r = factors[cfac][1];
        ll mv = cpow (r, l - 2, l); // inverse of r mod l
        ll nx = (mv * (n % l)) % l;
        //cout << l << " " << r << " " << mv << " " << nx << "\n";
        return nx * r <= n;
    }
    else
    {
        int cloc = n % factors[cfac][0];
        //cout << dijk[cfac][cloc] << "\n";
        return dijk[cfac][cloc] <= n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    nfac = 0;
    for (int i = 0; i < MAXS; i++)
        p[i] = 0;
    p[1] = 1;
    for (int i = 2; i < MAXS; i++)
    {
        if (p[i] == 0)
        {
            for (int j = i; j < MAXS; j += i)
                p[j] = i;
            small_primes.push_back(i);
        }
    }

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N[i] >> K[i];

        fill(K[i]);
    }

    for (int i = 0; i < nfac; i++)
        solve_fac(i);

    for (int i = 0; i < T; i++)
    {
        ll n = N[i];
        int cfac = m[K[i]];

        if (works (n, cfac))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}