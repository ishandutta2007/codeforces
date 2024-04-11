#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
int par[MAXN];
int res[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            res[j] = 0;
        int cloc = i;
        while (!res[cloc])
        {
            res[cloc] = 1;
            cloc = par[cloc];
        }
        cout << cloc + 1 << " ";
    }
    cout << "\n";
}