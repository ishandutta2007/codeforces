#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

const int N = 1e5 + 34;

int n, m, kol;
bool u[N], uu[N];
int x[N], ans;
char ch[N];
int lp = -1, lm = -1;
set <int> s, bos;


int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ch[i] >> x[i];
        if (!uu[x[i]] && ch[i] == '-')
            s.insert(x[i]);
        uu[x[i]] = true;
    }

    for (int i = 0; i < m; i++) {
        /*if (ch[i] == '+' && s.empty())
            bos.insert(x[i]);*/
        if (ch[i] == '+' && !s.empty())
            u[x[i]] = true;

        if (i > 0 && x[i - 1] != x[i]) {
            if (ch[i - 1] == '-')
                u[x[i - 1]] = true;
            if (ch[i] == '+')
                u[x[i]] = true;
        }

        if (ch[i] == '+')
            s.insert(x[i]);
        if (ch[i] == '-' && s.find(x[i]) != s.end())
            s.erase(x[i]);

        if (ch[i] == '-' && !s.empty())
            u[x[i]] = true;
        /*if (ch[i] == '-' && s.empty())
            bos.insert(x[i]);*/
    }

    if (bos.size() > 1) {

    }

    for (int i = 1; i <= n; i++)
        if (!u[i])
            ans++;

    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
        if (!u[i])
            printf("%d ", i);

    return 0;
}