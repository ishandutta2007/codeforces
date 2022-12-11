#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

string n[102];
string sn[102];
string ans = "";

int c[102];
bool use[102];
int main()
{
    int N;
    cin >> N;
    FOR(i, N)
    {
        cin >> n[i];
        n[i] += ' ';
    }
    FOR(i, N)
    {
        cin >> sn[i];
        sn[i] += ", ";
    }

    sort(n, n + N);
    sort(sn, sn + N);
    clr(c);

    FOR(i, N)
        c[(int)(n[i][0] - 'A')]++;

    FOR(i, N)
        c[(int)(sn[i][0] - 'A')]--;
    clr(use);

    FOR(i, N)
    {
        int j = 0;
        if (c[n[i][0] - 'A'] > 0)
        {
            while (j < N && (use[j] ||(n[i][0] != sn[j][0] && c[sn[j][0] - 'A'] >= 0))) j++;
        }
        else{
            while (j < N && (use[j] || (sn[j][0] != n[i][0]))) j++;
        }
        use[j] = true;
        c[n[i][0] - 'A']--;
        c[sn[j][0] - 'A']++;

        ans += n[i] + sn[j];
    }
    ans.erase(ans.length() - 2, 2);
    cout << ans;
    return 0;
}