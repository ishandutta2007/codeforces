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

vector<vector<int>> list_gr;
vector<int> tp_srt;
vector<char> clr;

bool top_sort(int v)
{
    if (clr[v] == 'g')
        return false;
    clr[v] = 'g';
    for (auto x : list_gr[v])
        if (clr[x] != 'b')
            if (!top_sort(x))
                return false;
    tp_srt.push_back(v);
    clr[v] = 'b';
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    list_gr.resize(n);
    clr.resize(n, 'w');
    vector<int> courses(k);
    for (auto &x : courses)
    {
        cin >> x;
        --x;
    }
    for (int i = 0; i < n; ++i)
    {
        int amnt;
        cin >> amnt;
        list_gr[i].resize(amnt);
        for (auto &x : list_gr[i])
        {
            cin >> x;
            --x;
        }
    }
    for (auto x : courses)
        if (clr[x] != 'b' && !top_sort(x))
        {
            cout << -1 << endl;
            return 0;
        }
    cout << tp_srt.size() << endl;
    for (auto x : tp_srt)
        cout << x + 1 << " ";
    cout << endl;
}