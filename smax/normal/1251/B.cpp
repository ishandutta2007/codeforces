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
        int n, ret = 0, numOdd = 0, numEvenE = 0, numEvenO = 0;
        cin >> n;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            if (s.length() % 2) {
                ret++;
                numOdd++;
            } else {
                int numOnes = 0;
                for (char c : s)
                    numOnes += c == '1';
                if (numOnes % 2)
                    numEvenO++;
                else {
                    numEvenE++;
                    ret++;
                }
            }
        }
        if (numOdd > 0)
            ret += numEvenO;
        else
            ret += numEvenO - numEvenO % 2;

        cout << ret << "\n";
    }

    return 0;
}