#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 2000100;

int N;
int l[MAXN], r[MAXN];
vector <int> edge[MAXN];
map <int, int> mm;
int ss[MAXN], ns, nt;

int ndeg, nseen, nhi, nsec;
bool seen[MAXN];

void flood (int cloc)
{
    seen[cloc] = true;
    nsec = max (nsec, cloc);
    if (nhi < nsec)
        swap (nhi, nsec);
    ndeg += edge[cloc].size();
    nseen++;

    for (int neigh : edge[cloc])
        if (!seen[neigh]) flood (neigh);
}

int search (int x)
{
    int lo = 0, hi = nt - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (ss[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> l[i] >> r[i];
        ss[2*i] = l[i];
        ss[2*i+1] = r[i];
    }
    ns = 2 * N;
    sort (ss, ss + ns);
    nt = 0;
    for (int i = 0; i < ns; i++)
    {
        if (i == 0 || ss[i] != ss[i-1])
            ss[nt++] = ss[i];
    }

    for (int i = 0; i < N; i++)
    {
        int x = search (l[i]), y = search (r[i]);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 0; i < MAXN; i++)
        seen[i] = false;
    int ans = -1;
    bool bad = false;
    for (int i = 0; i < nt; i++)
    {
        if (seen[i]) continue;
        ndeg = nseen = 0;
        nhi = nsec = 0;
        flood (i);

        if (ndeg > 2 * nseen)
            bad = true;
        else if (ndeg == 2 * nseen)
            ans = max (ans, nhi);
        else
            ans = max (ans, nsec);
    }

    if (bad) cout << "-1\n";
    else cout << ss[ans] << "\n";
}