#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b, s1, s2;

bool check(int l)
{
    s1.clear();
    s2.clear();
    int n = a.length();
    int r = n;
    vector<int> v;
    for (int i = 0; i < a.length(); ++i)
    {
        if (v.size() >= b.length() - l)
            break;
        if (b[v.size()] == a[i])
        {
            v.push_back(i);
            s1.push_back(a[i]);
        }
    }
    if (v.size() >= b.length() - l)
        return true;
    while (v.size() < b.length() - l)
    {
        v.push_back(n);
        s1.push_back('0');
    }
    for (int i = 0; i < b.length() - l; ++i)
    {
        for (r = r - 1; r > -1; --r)
            if (a[r] == b[b.length() - 1 - i])
            {
                s2.push_back(a[r]);
                break;
            }
        v.pop_back();
        s1.pop_back();
        if ((v.size() > 0 && v.back() < r) || (v.size() == 0 && r > -1))
            return true;
    }
    return false;
}

int main()
{
    cin >> a >> b;
    int l = -1, r = b.length() + 1, c;
    while (r - l > 1)
    {
        c = (r + l) / 2;
        if (check(c))
            r = c;
        else
            l = c;
    }
    if (r == b.length())
    {
        cout << "-" << endl;
        return 0;
    }
    else
    {
        check(r);
        cout << s1;
        for (int i = (int)s2.length() - 1; i > -1; --i)
            cout << s2[i];
        cout << endl;
    }
}