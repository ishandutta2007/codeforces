#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
bool use[MAXN];
vector <pair <int, int> > ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;

    int lv = -1, hi = N;
    for (int i = 0; i < N - 1; i++)
    {
        int x; cin >> x;
        if (use[x])
        {
            while (use[hi]) hi--;
            cout << lv << " " << hi << "\n";
            use[hi] = true;
            hi--;
            lv = x;
        }
        else
        {
            use[x] = true;
            if (lv < 0)
            {
                cout << x << "\n";
            }
            else
                cout << lv << " " << x << "\n";
            lv = x;
        }
    }
    int ab = 1;
    while (use[ab]) ab++;
    cout << lv << " " << ab << "\n";
}