#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
using ld = long double;

int main()
{
    priority_queue<int> pr;
    int n;
    cin >> n;
    int last = n + 1;
    for (int i = 0; i < n; ++i)
    {
        int cur;
        cin >> cur;
        pr.push(cur);
        while (pr.size() && pr.top() == last - 1)
        {
            --last;
            cout << last << " ";
            pr.pop();
        }
        cout << endl;
    }
    while (pr.size() && pr.top() == last - 1)
    {
        cout << last - 1 << " ";
        pr.pop();
    }
}