#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using pss = pair<string, string>;

void make_kill(pss &p, pss kill)
{
    if (p.first == kill.first)
        p.first = kill.second;
    if (p.second == kill.first)
        p.second = kill.second;
}

int main()
{
    pss p;
    cin >> p.first >> p.second;
    cout << p.first << " " << p.second << endl;
    int n;
    cin >> n;
    pss kill;
    for (int i = 0; i < n; ++i)
    {
        cin >> kill.first >> kill.second;
        make_kill(p, kill);
        cout << p.first << " " << p.second << endl;
    }
}