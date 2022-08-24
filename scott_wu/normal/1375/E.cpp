#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int N;
int arr[MAXN];
vector <pair <int, pair <int, int> > > v;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i] > arr[j])
                v.push_back(make_pair (arr[i], make_pair (i, -j)));
    sort (v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second.first + 1 << " " << -v[i].second.second + 1 << "\n";
        swap (arr[v[i].second.first], arr[-v[i].second.second]);
    }
}