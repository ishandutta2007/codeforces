#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ans(n);
    string t = s;
    sort(t.begin(), t.end());
    int ind = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == t[ind])
        {
            ans[i] = 1;
            ind++;
            while(i > 0 && s[i - 1] == t[ind])
            {
                i--;
                ind++;
            }
            if(i > 0)
                ans[i - 1] = 1;
        }
    }
    for(int x : ans)
        cout << x << " ";
}