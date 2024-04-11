#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
int arr[MAXN];

int gcf (int a, int b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int g = K;
    for (int i = 0; i < N; i++)
    {
        g = gcf (g, arr[i] % g);
    }

    cout << K / g << "\n";
    for (int i = 0; i < K / g; i++)
    {
        if (i) cout << " ";
        cout << i * g;
    }
    cout << "\n";
}