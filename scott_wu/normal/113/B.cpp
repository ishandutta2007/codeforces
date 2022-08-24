#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll pow[2100];
ll ps[2100];
vector <ll> blah;
int n, blen, elen;

ll hash (int start, int len)
{
    return ps[start+len] - pow[len] * ps[start];
}

int main()
{
    pow[0] = 1;
    for (int i = 1; i < 2100; i++)
        pow[i] = pow[i-1] * 101;
    string str, beg, end;
    cin >> str >> beg >> end;
    n = str.length();
    ps[0] = 0;
    for (int i = 0; i < n; i++)
        ps[i+1] = 101 * ps[i] + (int) (str[i] - 'a');
    ll h[2];
    h[0] = h[1] = 0;
    for (int i = 0; i < beg.length(); i++)
        h[0] = 101 * h[0] + (int) (beg[i] - 'a');
    for (int i = 0; i < end.length(); i++)
        h[1] = 101 * h[1] + (int) (end[i] - 'a');
    int blen = beg.length();
    int elen = end.length();
    int ans = 0;
    for (int len = max (blen, elen); len <= n; len++)
    {
        //if (len > max (blen, elen)) return 0;
        blah.clear();
        for (int i = 0; i <= n - len; i++)
            if (hash (i, blen) == h[0] && hash (i+len-elen, elen) == h[1])
                blah.push_back (hash (i, len));
        sort (blah.begin(), blah.end());
        ans += blah.size();
        if (blah.size() != 0)
        for (int j = 0; j < blah.size() - 1; j++)
        {
            if (blah[j] == blah[j+1])
                ans--;
        }
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}