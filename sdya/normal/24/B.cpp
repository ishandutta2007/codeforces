#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

map < string, int > MP;
string names[100];
int wins[100][100];
int points[100];
int num1[100], num2[100];

int a[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

bool comp1(int p, int q)
{
    if (points[p] > points[q]) return true;
    if (points[p] < points[q]) return false;

    for (int i = 1; i <= 60; i ++)
    {
        if (wins[p][i] > wins[q][i]) return true;
        if (wins[p][i] < wins[q][i]) return false;
    }
    return true;
}

bool comp2(int p, int q)
{
    if (wins[p][1] > wins[q][1]) return true;
    if (wins[p][1] < wins[q][1]) return false;

    if (points[p] > points[q]) return true;
    if (points[p] < points[q]) return false;

    for (int i = 1; i <= 60; i ++)
    {
        if (wins[p][i] > wins[q][i]) return true;
        if (wins[p][i] < wins[q][i]) return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int v = 0;

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
    {
        int n;
        scanf("%d", &n);
        for (int j = 1; j <= n; j ++)
        {
            string s;
            cin >> s;
            if (MP.count(s) == 0) v ++, MP[s] = v, names[v] = s;
            int cur = MP[s];
            wins[cur][j] ++;
            if (j <= 10)
                points[cur] += a[j - 1];
        }
    }

    for (int i = 1; i <= v; i ++)
        num1[i] = num2[i] = i;

    for (int i = 1; i <= v; i ++)
        for (int j = i + 1; j <= v; j ++)
        {
            if (!comp1(num1[i], num1[j]))
                swap(num1[i], num1[j]);
            if (!comp2(num2[i], num2[j]))
                swap(num2[i], num2[j]);
        }


    cout << names[num1[1]] << endl;
    cout << names[num2[1]] << endl;


    return 0;
}