#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

set <pair<int, int> > s;
int a[200000], b[20000];

bool cmp(int q, int w)
{
    return a[q] < a[w];
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, q, k;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    for (int i = 0; i < q; i++)
    {
        int tp, id;
        cin >> tp >> id;
        if (tp == 2)
        {
            int f = 0;
            for (int j = 0; j < k; j++)
                if (b[j] == id) f = 1;
            cout << (f? "YES\n" : "NO\n");
        }
        else
        {
            b[k] = id;
            sort(b, b + k + 1, cmp);
            b[0] = b[k];
        }
    }
    return 0;
}