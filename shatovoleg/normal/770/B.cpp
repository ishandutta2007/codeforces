#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>

using namespace std;
using pii = pair<int, int>;
using ll = unsigned long long;
using ld = long double;

string mx(string a, string b)
{
    int sm1 = 0, sm2 = 0;
    for (auto x : a)
        sm1 += x - '0';
    for (auto x : b)
        sm2 += x - '0';
    if (sm1 != sm2)
    {
        if (sm1 > sm2)
            return a;
        return b;
    }
    if (a.length() != b.length())
    {
        if (a.length() > b.length())
            return a;
        return b;
    }
    if (a < b)
        return b;
    return a;
}

string get_max_num(string s)
{
    if (!s.length())
        return s;
    string ans1;
    string ans2 = string(1, s[0]);
    if (s[0] > '1')
        ans1 += s[0] - 1;
    ans1 += string(s.length() - 1, '9');
    ans2 += get_max_num(s.substr(1));
    return mx(ans1, ans2);
}

int main()
{
    string s;
    cin >> s;
    cout << get_max_num(s) << endl;
}