#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 400100;
const int P = (1 << 19);
const int MAXP = 2 * P + 100;
const ll MOD = 1e9 + 7;

int N;
map <int, int> atime;
int arr[MAXN], ct[MAXN];

set <int> buy, sell, unordered;


int main()
{
    ios_base::sync_with_stdio(0);
    buy.insert(-1);
    sell.insert(1e9);

    cin >> N;
    ll res = 1;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        if (s[1] == 'D')
            ct[i] = 0;
        else
            ct[i] = 1;
        cin >> arr[i];

        if (ct[i] == 0)
        {
            int cval = arr[i];
            if (cval > *sell.begin())
                sell.insert(cval);
            else if (cval < *buy.rbegin())
                buy.insert(cval);
            else
                unordered.insert(cval);
        }
        else
        {
            int cval = arr[i];
            if (cval < *buy.rbegin())
                res = 0;
            else if (cval > *sell.begin())
                res = 0;
            else
            {
                if (cval == *buy.rbegin())
                {
                    buy.erase(cval);
                }
                else if (cval == *sell.begin())
                {
                    sell.erase(cval);
                }
                else
                {
                    res = (res * 2) % MOD;
                    unordered.erase(cval);
                }
                for (set<int>::iterator it = unordered.begin(); it != unordered.end(); it++)
                {
                    if (*it > cval)
                        sell.insert(*it);
                    else
                        buy.insert(*it);
                }
                unordered.clear();
            }
        }
    }

    int nc = (unordered.size()) + 1;
    res = (res * nc) % MOD;

    cout << res << "\n";
}