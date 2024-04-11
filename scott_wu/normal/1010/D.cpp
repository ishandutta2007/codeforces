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
const int MAXN = 1000100;

int N;
// IN=0, AND=1, OR=2, XOR=3, NOT=4
int op[MAXN], a[MAXN], b[MAXN];
int res[MAXN];
int willwork[MAXN];

void flood (int cloc)
{
    int o = op[cloc];
    if (o == 0)
    {
        res[cloc] = a[cloc];
        return;
    }

    flood (a[cloc]);
    if (o != 4)
        flood (b[cloc]);

    if (o == 4)
    {
        res[cloc] = 1 - res[a[cloc]];
    }
    if (o == 1)
    {
        res[cloc] = res[a[cloc]] & res[b[cloc]];
    }
    if (o == 2)
    {
        res[cloc] = res[a[cloc]] | res[b[cloc]];
    }
    if (o == 3)
    {
        res[cloc] = res[a[cloc]] ^ res[b[cloc]];
    }
}

void flood2 (int cloc)
{
    willwork[cloc] = 1;
    int o = op[cloc];
    if (o == 0)
    {
        return;
    }

    int ac = a[cloc], bc = b[cloc];
    if (o == 4)
    {
        flood2 (ac);
    }
    if (o == 1)
    {
        if (res[bc])
            flood2 (ac);
        if (res[ac])
            flood2 (bc);
    }
    if (o == 2)
    {
        if (!res[bc])
            flood2 (ac);
        if (!res[ac])
            flood2 (bc);
    }
    if (o == 3)
    {
        flood2 (ac);
        flood2 (bc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        if (s[0] == 'I')
            op[i] = 0;
        else if (s[0] == 'A')
            op[i] = 1;
        else if (s[0] == 'O')
            op[i] = 2;
        else if (s[0] == 'X')
            op[i] = 3;
        else if (s[0] == 'N')
            op[i] = 4;

        cin >> a[i];
        if (op[i] > 0)
            a[i]--;
        if (op[i] >= 1 && op[i] <= 3)
        {
            cin >> b[i];
            b[i]--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        willwork[i] = res[i] = 0;
    }

    flood (0);
    flood2 (0);

    for (int i = 0; i < N; i++)
    {
        if (op[i] != 0) continue;
        if (willwork[i])
            cout << 1 - res[0];
        else
            cout << res[0];
    }
    cout << "\n";
}