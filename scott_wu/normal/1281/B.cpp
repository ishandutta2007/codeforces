#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string hleft, hright;

bool cmp (int x, int y)
{
    if (hleft[x] != hleft[y]) return hleft[x] < hleft[y];
    return x > y;
}

void gogo()
{
    cin >> hleft >> hright;
    vector <int> v;
    for (int i = 0; i < hleft.size(); i++)
        v.push_back(i);
    sort (v.begin(), v.end(), cmp);

    int cloc = 0;
    for (int i = 0; i < hleft.size(); i++)
    {
        while (v[cloc] < i) cloc++;
        swap (hleft[i], hleft[v[cloc]]);
        if (hleft < hright)
        {
            cout << hleft << "\n";
            return;
        }
        swap (hleft[i], hleft[v[cloc]]);
    }
    cout << "---\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}