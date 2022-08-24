#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;
    vector <int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort (v.begin(), v.end());
    vector <int> ans;
    for (int i = 0; i < N; i++)
        if (i % 2 == 0)
            ans.push_back(v[i/2]);
        else
            ans.push_back(v[N-1-i/2]);
    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}