#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a[4];
        for(int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }
        int d[2] = {a[0] + a[2] + a[3], a[1] + a[2] + a[3]};
        string s;
        cin >> s;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            d[s[i] - 'A']--;
        }
        if(d[0] || d[1])
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> v[3];
        int last = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == n - 1 || s[i] == s[i + 1])
            {
                if(last < i)
                {
                    if((i - last) % 2)
                    {
                        v[s[last] - 'A'].push_back((i - last + 1) / 2);
                    }
                    else
                    {
                        v[2].push_back((i - last + 1) / 2);
                    }
                }
                last = i + 1;
            }
        }
        sort(v[0].begin(), v[0].end(), greater<int>());
        sort(v[1].begin(), v[1].end(), greater<int>());
        while(v[0].size())
        {
            int x = v[0].back();
            v[0].pop_back();
            if(x <= a[2])
            {
                a[2] -= x;
            }
            else
            {
                x -= a[2];
                a[2] = 0;
                v[0].push_back(x);
                for(int y : v[0])
                {
                    v[2].push_back(y - 1);
                    v[0].clear();
                }
            }
        }
        while(v[1].size())
        {
            int x = v[1].back();
            v[1].pop_back();
            if(x <= a[3])
            {
                a[3] -= x;
            }
            else
            {
                x -= a[3];
                a[3] = 0;
                v[1].push_back(x);
                for(int y : v[1])
                {
                    v[2].push_back(y - 1);
                    v[1].clear();
                }
            }
        }
        while(v[2].size())
        {
            int x = v[2].back();
            v[2].pop_back();
            if(x <= a[2])
            {
                a[2] -= x;
            }
            else if(a[2])
            {
                x -= a[2];
                a[2] = 0;
                v[2].push_back(x);
            }
            else if(x <= a[3])
            {
                a[3] -= x;
            }
            else if(a[3])
            {
                x -= a[3];
                a[3] = 0;
                v[2].push_back(x);
            }
        }
        if(a[2] + a[3])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}