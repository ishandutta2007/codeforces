#include <iostream>
#include <string>
#include <cstdio>
#define fr(i, n) for(int i = 0; i < n; i++)

using namespace std;

string s[100];
int n, m, ans;
bool ok;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    fr(i, n)
        cin >> s[i];

    fr(i, n)
        fr(j, m){
            ok = true;
            fr(ii, m)
                if (s[i][ii] == 'S')
                    ok = false;
            if (ok){
                ans++;
                continue;
            }
            ok = true;
            fr(ii, n)
                if (s[ii][j] == 'S')
                    ok = false;
            if (ok)
                ans++;
        }
    cout << ans;
    return 0;
}