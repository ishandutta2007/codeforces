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
const int MAXN = 1100;

int N;
int arr[MAXN];
vector <int> res;

bool works (int cc)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != arr[i%cc])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = N - 1; i >= 1; i--)
        arr[i] -= arr[i-1];


    for (int i = 1; i <= N; i++)
        if (works (i))
            res.push_back(i);

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}