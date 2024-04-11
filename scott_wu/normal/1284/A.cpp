#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, M;
string s[MAXN], t[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < M; i++)
        cin >> t[i];

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int x; cin >> x;
        x--;
        cout << s[x%N] << t[x%M] << "\n";
    }

}