#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] = i - arr[i];
    }
    int cloc = 0;
    for (int i = 0; i < 2 * N; i++)
        cloc = arr[cloc];

    int oloc = cloc;
    vector <int> v;
    do {
        v.push_back (cloc);
        cloc = arr[cloc];
    } while (cloc != oloc);
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (i) cout << " ";
        cout << v[i] + 1;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}