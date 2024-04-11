#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t, n, m;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << min(min(n, m), (n+m)/4) << '\n';
    }
}