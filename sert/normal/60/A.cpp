#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
const int N = 1e6 + 7;

string s;
int n, m, st, x, p, kol;
bool u[N];

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;

    fr(i, m){
        cin >> s >> s >> s;
        if (s[0] == 'r') st = -1;
        else st = 1;
        cin >> s >> x;
        p = x - 1;
        while(true){
            u[p] = true;
            p += st;
            if (p < 0 || p >= n)
                break;
        }
    }

    fr(i, n)
        if (!u[i])
            kol++;

    if (kol == 0)
        cout << -1;
    else
        cout << kol;

    return 0;
}