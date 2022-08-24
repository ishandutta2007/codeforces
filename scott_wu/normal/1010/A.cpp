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
const int MAXN = 1100;

int N, M;
int A[MAXN], B[MAXN];
vector <int> v;

bool works (double d)
{
    double vs = d + M;
    for (int i = 0; i < v.size(); i++)
    {
        vs = (vs * ((double) v[i] - 1.0) / ((double) v[i]));
    }
    return vs >= M;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        v.push_back(A[i]);
        v.push_back(B[(i+1)%N]);
    }

    double lo = 0, hi = 1e10;
    for (int run = 0; run < 100; run++)
    {
        double mid = (lo + hi) / 2;
        if (works (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    if (lo > 2e9)
    {
        cout << "-1\n";
    }
    else
    {
        cout << fixed << setprecision(7);
        cout << lo << "\n";
    }
}