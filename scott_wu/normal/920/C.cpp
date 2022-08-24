#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000100;
int N;
int arr[MAXN];
int hi[MAXN];
string s;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i =0 ; i < N; i++)
        cin >> arr[i];
    hi[N-1] = arr[N-1];
    for (int i = N - 2; i >= 0; i--)
        hi[i] = min (hi[i+1], arr[i]);

    cin >> s;
    bool bad = false;

    int lo = arr[0];
    for (int i = 0; i < N - 1; i++)
    {
        lo = max (lo, arr[i]);
        if (lo > hi[i+1])
            if (s[i] == '0')
            {
                cout << "NO\n";
                exit(0);
            }
    }
    cout << "YES\n";
}