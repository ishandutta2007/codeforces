#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, bool> pib;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    vector<pib> mouses(n);
    {
        string s;
        int v;
        for (auto &x : mouses)
        {
            cin >> x.first;
            cin >> s;
            x.second = (s[0] == 'U');
        }
    }
    sort(mouses.begin(), mouses.end());
    ll sum = 0;
    int cnt = 0;
    for (auto x : mouses)
    {
        if (x.second)
        {
            if (a > 0)
            {
                --a;
                ++cnt;
                sum += x.first;
            }
            else
                if (c > 0)
                {
                    --c;
                    ++cnt;
                    sum += x.first;
                }
        }
        else
        {
            if (b > 0)
            {
                --b;
                ++cnt;
                sum += x.first;
            }
            else
                if (c > 0)
                {
                    --c;
                    ++cnt;
                    sum += x.first;
                }
        }
    }
    cout << cnt << " " << sum << endl;
}