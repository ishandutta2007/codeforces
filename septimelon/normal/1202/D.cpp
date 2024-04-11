#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    stack<int> ans;
    for (int qq = 0; qq < t; qq++) {
        while (!ans.empty())
            ans.pop();
        ll k = 44721;
        ll n;
        cin >> n;
        while (n > 0) {
            while (k * (k-1) / 2 > n)
                k--;
            ans.push(k);
            n -= k * (k-1) / 2;
        }
        cout << "1";
        int cou = 0;
        while (!ans.empty()) {
            while (ans.top() > cou) {
                cou++;
                cout << "3";
            }
            cout << "7";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}