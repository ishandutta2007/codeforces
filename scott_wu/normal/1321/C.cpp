#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
vector <int> v;
vector <int> v2;

int main()
{
    ios_base::sync_with_stdio(0);

    int N; cin >> N;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        v.push_back(s[i] - 'a');

    while (true)
    {
        int aloc = -1, av = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if ((i && v[i-1] + 1 == v[i]) || (i + 1 < v.size() && v[i+1] + 1 == v[i]))
            {
                if (v[i] > av)
                {
                    av = v[i];
                    aloc = i;
                }
            }
        }
        if (aloc < 0) break;

        v2.clear();
        for (int i = 0; i < v.size(); i++)
            if (i != aloc)
                v2.push_back(v[i]);
        v = v2;
    }

    cout << s.length() - v.size() << "\n";
}