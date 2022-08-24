#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
int arr[MAXN];

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int r = N;
    for (int i = 0; i < N - 1; i++)
        if (gcd (arr[i], arr[i+1]) > 1)
            r++;
    cout << r - N << "\n";

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << arr[i];
        if (i < N - 1 && gcd (arr[i], arr[i+1]) > 1)
            cout << " 1";
    }
    cout << "\n";
}