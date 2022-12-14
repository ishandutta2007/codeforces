#include <bits/stdc++.h>
using namespace std;
int t, n, x;
deque<int> Q;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Q.clear();
        cin >> n >> x;
        Q.push_back(x);
        while (--n) {
            cin >> x;
            if (x <= Q.front()) Q.push_front(x);
            else Q.push_back(x);
        }
        while (!Q.empty()) cout << Q.front() << ' ', Q.pop_front();
        cout << '\n';
    }
}