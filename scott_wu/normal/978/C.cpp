#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
ll arr[MAXN];
ll b[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];


    int cloc = 0;
    ll ctot = -1;
    for (int i = 0; i < M; i++)
    {
        ll cscore = b[i];
        if (i)
            cscore -= b[i-1];
        ctot += cscore;
        while (ctot >= arr[cloc])
        {
            ctot -= arr[cloc];
            cloc++;
        }
        cout << cloc + 1 << " " << ctot + 1 << "\n";
    }
}