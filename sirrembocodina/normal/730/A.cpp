#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<int> vc;

bool check(int cur, vector<string> &ans)
{
    vector<int> d(vc.size());
    int sum = 0;
    for(int i = 0; i < vc.size(); ++i)
    {
        d[i] = vc[i] - cur;
        if(d[i] < 0) return 0;
        sum += d[i];
    }
    if(sum == 0) return 1;
    set<pair<int, int> > st;
    for(int i = 0; i < d.size(); ++i)
    {
        if(d[i] > 0)
            st.insert(make_pair(-d[i], i));
    }
    if(sum % 2 == 1)
    {
        if(st.size() < 3)
            return 0;
        pair<int, int> t[3];
        auto it = st.begin();
        for(int j = 0; j < 3; ++j)
            t[j] = *(it++);
        string s = "";
        for(int k = 0; k < d.size(); ++k)
            s.push_back('0');
        for(int j = 0; j < 3; ++j)
        {
            s[t[j].second] = '1';
            st.erase(t[j]);
            t[j].first++;
            if(t[j].first < 0)
                st.insert(t[j]);
        }
        ans.push_back(s);
    }
    while(!st.empty())
    {
        if(st.size() < 2) return 0;
        pair<int, int> t[2];
        auto it = st.begin();
        for(int j = 0; j < 2; ++j)
            t[j] = *(it++);
        string s;
        for(int j = 0; j < d.size(); ++j)
            s.push_back('0');
        for(int j = 0; j < 2; ++j)
        {
            s[t[j].second] = '1';
            st.erase(t[j]);
            t[j].first++;
            if(t[j].first < 0)
                st.insert(t[j]);
        }
        ans.push_back(s);
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vc.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> vc[i];
    for(int i = 100; i >= 1; --i)
    {
        vector<string> ans;
        bool ok = check(i, ans);
        if(ok)
        {
            cout << i << endl;
            cout << ans.size() << endl;
            for(int j = 0; j < ans.size(); ++j)
                cout << ans[j] << endl;
            return 0;
        }
    }
    vector<string> ans;
    for(int i = 0; i < 100; ++i)
    {
        for(int j = 0; j + 1 < n; ++j)
        {
            ans.push_back("");
            for(int k = 0; k < n; ++k)
                ans.back().push_back('0');
            ans.back()[j] = ans.back()[j + 1] = '1';
        }
    }
    cout << 0 << endl;
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    return 0;
}