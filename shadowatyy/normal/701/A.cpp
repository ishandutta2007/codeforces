#include <bits/stdc++.h>
using namespace std;

int n;

int t[107];

vector<int> v;

bool comp(int a, int b)
{
    return t[a]<t[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];

        v.push_back(i);
    }

    sort(v.begin(), v.end(), comp);

    for(int p = 0, k = n-1; p<k; ++p, --k)
    {
        cout << v[p] << " " << v[k] << '\n';
    }
}