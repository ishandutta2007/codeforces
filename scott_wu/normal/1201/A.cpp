#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
string s[MAXN];

int cnt[5];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> s[i];

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int p; cin >> p;

        for (int j = 0; j < 5; j++)
            cnt[j] = 0;
        for (int j = 0; j < N; j++)
            cnt[s[j][i]-'A']++;
        int cv = 0;
        for (int j = 0; j < 5; j++)
            cv = max (cv, cnt[j]);
        ans += cv * p;
    }
    cout << ans << "\n";
}