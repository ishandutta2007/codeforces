#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
string s[100];
map < string, int > MP;

int a[100], gz[100], gp[100];

int num[100];

bool comp(int p, int q)
{
    if (a[p] > a[q]) return true;
    if (a[q] > a[p]) return false;
    if (gz[p] - gp[p] > gz[q] - gp[q]) return true;
    if (gz[p] - gp[p] < gz[q] - gp[q]) return false;
    return (gz[p] > gz[q]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i ++)
        cin >> s[i], MP[s[i]] = i, num[i] = i;

    for (int i = 1; i <= (n * (n - 1)) / 2; i ++)
    {
        string r;
        int x, y;
        cin >> r;
        scanf("%d:%d", &x, &y);
        string s1 = "", s2 = "";
        bool good = false;
        for (int j = 0; j < r.size(); j ++)
            if (r[j] == '-') good = true; else
            if (!good)
                s1 += r[j]; else
                s2 += r[j];
        int p = MP[s1], q = MP[s2];
        gz[p] += x, gz[q] += y;
        gp[p] += y, gp[q] += x;
        if (x == y)
            a[p] ++, a[q] ++; else
            if (x > y)
                a[p] += 3; else
                a[q] += 3;
    }

    sort(num + 1, num + n + 1, comp);

    vector < string > res;
    for (int i = 1; i <= n / 2; i ++)
        res.push_back(s[num[i]]);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << endl;
    return 0;
}