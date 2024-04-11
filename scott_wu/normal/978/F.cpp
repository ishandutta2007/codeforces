#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, K;
int arr[MAXN];
pair <int, int> ord[MAXN]; // r, ind
int deg[MAXN];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ord[i] = make_pair (arr[i], i);
    }

    sort (ord, ord + N);
    int clast = 0;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && ord[i].first != ord[i-1].first)
            clast = i;
        deg[ord[i].second] = clast;
    }

    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (arr[a] > arr[b])
            deg[a]--;
        if (arr[b] > arr[a])
            deg[b]--;
    }

    for (int i = 0; i < N; i++)
        cout << deg[i] << " ";
}