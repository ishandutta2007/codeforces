#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;

int N;
string s;
int wc;

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> s;
    N = s.length();
    wc = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (s[i] == 'v' && s[i+1] == 'v')
            wc++;
    }

    ll ans = 0;
    int nw = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'v' && s[i+1] == 'v')
            nw++;
        if (s[i] == 'o')
        {
            ans += ((ll) nw * ((ll) wc - nw));
        }
    }
    cout << ans << "\n";
}