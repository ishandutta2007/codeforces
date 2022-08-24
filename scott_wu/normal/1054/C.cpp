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
const int MAXN = 1100;

int N;
int l[MAXN], r[MAXN];
pair <int, int> ord[MAXN];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> l[i];
    }
    for (int i = 0; i < N; i++)
        cin >> r[i];
    for (int i = 0; i < N; i++)
    {
        ord[i] = make_pair (l[i] + r[i], i);
    }
    sort (ord, ord + N);

    int cloc = 0;
    while (cloc < N)
    {
        if (ord[cloc].first != cloc)
        {
            cout << "NO\n";
            return 0;
        }
        int nloc = cloc;
        while (nloc < N && ord[nloc].first == ord[cloc].first)
            nloc++;
        for (int i = cloc; i < nloc; i++)
        {
            ans[ord[i].second] = cloc;
        }
        cloc = nloc;
    }

    bool bad = false;
    for (int i = 0; i < N; i++)
    {
        int lc = 0, rc = 0;
        for (int j = 0; j < i; j++)
            if (ans[i] > ans[j])
                lc++;
        for (int j = i + 1; j < N; j++)
            if (ans[i] > ans[j])
                rc++;
        if (lc != l[i] || rc != r[i])
            bad = true;
    }
    if (bad)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << N - ans[i];
    }
    cout << "\n";
}