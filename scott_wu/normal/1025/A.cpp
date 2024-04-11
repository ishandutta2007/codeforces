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
const int MAXN = 100100;

int N;
char c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i];
    sort (c, c + N);

    int ncount = 1;
    for (int i = 0; i < N - 1; i++)
        if (c[i] != c[i+1])
            ncount++;

    if (ncount == N && N > 1)
    {
        cout << "No\n";
    }
    else
        cout << "Yes\n";
}