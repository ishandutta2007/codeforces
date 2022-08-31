#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const int MAXN = 100100;

int N;
int arr[MAXN];
int m[MAXN];
int ps[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        m[i] = arr[i] - i;
    }

    ps[N-1] = m[N-1];
    for (int i = N - 2; i >= 0; i--)
        ps[i] = max (ps[i+1], m[i]);

    long long res = 0;
    int ccount = 0;
    for (int i = 0; i < N; i++)
    {
        ccount = max (ccount, ps[i] + i);
        res += ccount - arr[i];
        //cout << ccount << " " << arr[i] << "\n";
    }
    cout << res << "\n";
}