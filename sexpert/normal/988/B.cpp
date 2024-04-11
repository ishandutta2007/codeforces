#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2)
{
    return (s1.length() < s2.length());
}

int main()
{
    vector<string> ss;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ss.push_back(s);
    }
    sort(ss.begin(), ss.end(), comp);
    bool valid = true, flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = false;
        string s1 = ss[i], s2 = ss[i + 1];
        for(int a = 0; a < s2.length(); a++)
        {
            for(int b = 1; b <= 100; b++)
            {
                if(s2.substr(a, b) == s1) flag = true;
            }
        }
        if(!flag) valid = false;
    }
    if(!valid) cout << "NO";
    else
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            cout << ss[i] << endl;
        }
    }
}