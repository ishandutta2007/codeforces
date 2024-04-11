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
const int MAXN = 200100;

int N, M;
int X[MAXN], T[MAXN];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    N += M;

    for (int i = 0; i < N; i++)
        cin >> X[i];
    for (int i = 0; i < N; i++)
        cin >> T[i];

    int lv = -1;
    for (int i = 0; i < N; i++)
    {
        if (!T[i]) ans[i] = lv;
        else lv = i;
    }

    lv = N;
    for (int i = N - 1; i >= 0; i--)
    {
        if (!T[i])
        {
            if (ans[i] == -1 || (lv != N && X[lv] - X[i] < X[i] - X[ans[i]]))
                ans[i] = lv;
            ans[ans[i]]++;
        }
        else
            lv = i;
    }

    for (int i = 0; i < N; i++)
        if (T[i]) cout << ans[i] << " ";
    cout << "\n";
}