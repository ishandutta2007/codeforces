#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int P = (1 << 20);
const int MAXP = 2 * P + 100;

int N;
int arr[MAXN];
int seg[MAXP];

void upd (int cloc)
{
    cloc += P;
    while (cloc)
    {
        seg[cloc]++;
        cloc /= 2;
    }
}

int cfind (int cloc)
{
    int res = 0;
    cloc += P;
    while (cloc > 1)
    {
        if (cloc & 1)
            res += seg[cloc-1];
        cloc /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ans += i - cfind(arr[i]);
        upd(arr[i]);
    }

    if (ans % 2 != N % 2)
        cout << "Um_nik\n";
    else
        cout << "Petr\n";
}