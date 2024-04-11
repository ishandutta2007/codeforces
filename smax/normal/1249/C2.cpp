#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;

        stack<int> ternary;
        while (n > 0) {
            ternary.push(n % 3);
            n /= 3;
        }

        vector<int> newTernary;
        while (!ternary.empty()) {
            int digit = ternary.top();
            ternary.pop();

            if (digit == 2) {
                bool add = true;
                for (int i=newTernary.size()-1; i>=0; i--) {
                    newTernary[i]++;
                    if (newTernary[i] == 1) {
                        add = false;
                        break;
                    }
                    newTernary[i] = 0;
                }
                if (add)
                    newTernary.insert(newTernary.begin(), 1);
                newTernary.push_back(0);
                while (!ternary.empty()) {
                    newTernary.push_back(0);
                    ternary.pop();
                }
            } else
                newTernary.push_back(digit);
        }

        long long ret = 0, power = 1;
        for (int i=newTernary.size()-1; i>=0; i--) {
            ret += power * newTernary[i];
            power *= 3;
        }

        cout << ret << "\n";
    }

    return 0;
}