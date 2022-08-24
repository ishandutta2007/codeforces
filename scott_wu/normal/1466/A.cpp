#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;
    vector <int> v;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        v.push_back (x);
    }

    set <int> s;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            s.insert (abs (v[j] - v[i]));
    cout << s.size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}