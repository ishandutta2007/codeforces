#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    ll ctot = 0;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        ll ntot = ctot + a;
        if (i) cout << " ";
        cout << ntot / M - ctot / M;
        ctot = ntot;
    }
    cout << "\n";
}