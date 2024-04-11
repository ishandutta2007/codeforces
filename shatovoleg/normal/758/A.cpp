#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n, mx = -10000000;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
        if (x > mx)
            mx = x;
    }
    int cnt = 0;
    for (auto x : v)
        cnt += mx - x;
    cout << cnt << endl;
}