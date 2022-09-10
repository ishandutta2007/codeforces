#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s, res, c;

deque <int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end());

    while(!v.empty())
    {
        c = v.back();

        v.pop_back();

        while(!v.empty() && c+v.front()<=4)
        {
            c += v.front();

            v.pop_front();
        }

        res ++;
    }

    cout << res;
}