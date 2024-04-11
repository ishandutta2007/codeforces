#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using ll = unsigned long long;
using ld = long double;

int count_ans1(vector<int> cnt1, vector<int> cnt2)
{
    int stroke = 0, v;
    for (int i = 0; i < 10; ++i)
    {
        stroke += cnt1[i];
        v = min(stroke, cnt2[i]);
        stroke -= v;
    }
    return stroke;
}

int count_ans2(vector<int> cnt1, vector<int> cnt2)
{
    int can_strike = cnt1[0], stroke = 0;
    for (int i = 1; i < 10; ++i)
    {
        int v = min(cnt2[i], can_strike);
        stroke += v;
        can_strike -= v;
        can_strike += cnt1[i];
    }
    return stroke;
}

int main()
{
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> cnt1(10, 0), cnt2(10, 0);
    for (auto x : a)
        ++cnt1[x - '0'];
    for (auto x : b)
        ++cnt2[x - '0'];
    cout << count_ans1(cnt1, cnt2) << " " << count_ans2(cnt1, cnt2) << endl;
}