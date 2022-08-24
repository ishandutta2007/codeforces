#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
int arr[MAXN];
int goal[MAXN];
int cr, garb;

bool nf[MAXN];
bool nr[MAXN];

void drop (vector <int> v)
{
    for (int i = 0; i < v.size(); i++)
        nr[v[i]] = true;
    for (int i = 0; i < N; i++)
    {
        if (nr[i]) cout << "\\";
        else cout << ".";
    }
    cout << "\n";
    cr++;

    for (int i = (int)v.size() - 2; i >= 0; i--)
        swap (goal[v[i]], goal[v[i+1]]);
    garb = v[0];
}

void put_loc (int x) // put x in garbage and make x the new garbage
{
    char d = '\\';
    if (x > garb) d = '/';

    for (int i = 0; i < N; i++)
    {
        if (i == x || i == garb) cout << d;
        else cout << ".";
    }
    cout << "\n";
    swap (goal[garb], goal[x]);
    garb = x;
    cr++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    bool done = true;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;

        if (arr[i] != i)
            done = false;
        goal[arr[i]] = i;
    }

    if (done)
    {
        cout << N << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) cout << ".";
            cout << "\n";
        }
        return 0;
    }

    cout << N - 1 << "\n";
    vector <int> v;
    for (int i = 0; i < N; i++)
    {
        if (!nf[i] && goal[i] != i)
        {
            v.push_back(i);
            int cloc = i;
            while (!nf[cloc])
            {
                nf[cloc] = true;
                cloc = goal[cloc];
            }
        }
    }

    drop (v);
    while (goal[garb] != garb)
    {
        int jloc = 0;
        while (goal[jloc] != garb) jloc++;
        put_loc (jloc);
    }

    for (int i = cr; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << ".";
            cout << "\n";
    }
}