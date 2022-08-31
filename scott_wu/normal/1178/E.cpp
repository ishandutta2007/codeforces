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
const int MAXN = 1000100;

int N;
string s;
bool use[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXN; i++)
        use[i] = false;
    
    cin >> s;
    N = s.length();

    int lo = 0, hi = N - 1;
    while (hi >= lo)
    {
        if (hi - lo <= 2)
        {
            use[lo] = true;
            break;
        }
        if (s[lo] == s[hi])
        {
            use[lo] = use[hi] = true;
            lo++;
            hi--;
            continue;
        }
        if (s[lo] == s[hi-1])
        {
            hi--;
            use[lo] = use[hi] = true;
            lo++;
            hi--;
            continue;
        }
        if (s[lo+1] == s[hi])
        {
            lo++;
            use[lo] = use[hi] = true;
            lo++;
            hi--;
            continue;
        }
        if (s[lo+1] == s[hi-1])
        {
            lo++;
            hi--;
            use[lo] = use[hi] = true;
            lo++;
            hi--;
            continue;
        }
        
    }

    for (int i = 0; i < N; i++)
        if (use[i]) cout << s[i];
    cout << "\n";
}