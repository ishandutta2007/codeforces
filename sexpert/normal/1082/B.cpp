#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "@";
    vector<int> v;
    int nu = 1;
    for(int i = 0; i < n; i++)
    {
        if(i < n && s[i] == s[i + 1])
            nu++;
        else
        {
            v.push_back(nu);
            nu = 1;
        }
    }
    int l = v.size();
    int ind = 0, ans = 0;
    if(s[0] == 'S')
        ind = 1;
    int nugs = (v.size() + 1 - ind)/2;
    //cout << nugs << endl;
    for(;ind < l;ind += 2)
    {
        int cand = v[ind];
        if(ind >= 1 && nugs >= 2)
        {
            cand = max(cand, v[ind] + 1);
            if(ind >= 2) 
            {
                if(v[ind - 1] == 1)
                {
                    cand = max(cand, v[ind] + v[ind - 2]);
                    if(nugs >= 3)
                        cand = max(cand, v[ind] + v[ind - 2] + 1);
                }
            }
        }
        if(ind <= l - 2 && nugs >= 2)
        {
            cand = max(cand, v[ind] + 1);
            if(ind <= l - 3)
            {
                if(v[ind + 1] == 1)
                {
                    cand = max(cand, v[ind] + v[ind + 2]);
                    if(nugs >= 3)
                        cand = max(cand, v[ind] + v[ind + 2] + 1);
                }
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
}