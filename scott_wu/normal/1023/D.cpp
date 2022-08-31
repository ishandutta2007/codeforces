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
const int MAXN = 200100;

int N, Q;
int arr[MAXN];
bool used[MAXN];
set <int> s;

bool works()
{
    for (int i = 0; i <= Q; i++)
        used[i] = false;
    s.clear();

    for (int i = 0; i < N; i++)
    {
        int nval = arr[i];
        if (used[nval])
            return false;
        s.insert(nval);
        auto it = s.find(nval);
        it++;
        while (it != s.end())
        {
            int nlose = *it;
            it++;
            used[nlose] = true;
            s.erase(nlose);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int oloc = -1, qloc = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == Q)
            qloc = i;
        if (arr[i] == 0)
            oloc = i;
    }

    if (qloc == -1)
    {
        if (oloc == -1)
        {
            cout << "NO\n";
            return 0;
        }
        arr[oloc] = Q;
        qloc = oloc;
    }
    int fval = -1, lval = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i])
        {
            if (fval == -1) fval = arr[i];
            lval = arr[i];
        }
        else
        {
            if (lval != -1) arr[i] = lval;
        }
    }
    if (fval == -1) fval = Q;
    for (int i = 0; i < N; i++)
        if (arr[i] == 0) arr[i] = fval;

    if (works())
    {
        cout << "YES\n";
        for (int i = 0; i < N; i++)
        {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << "\n";
    }
    else
        cout << "NO\n";
}