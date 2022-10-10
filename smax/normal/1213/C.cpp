#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q, lastDigit[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                {2, 4, 6, 8, 0, 0, 0, 0, 0, 0},
                                {3, 6, 9, 2, 5, 8, 1, 4, 7, 0},
                                {4, 8, 2, 6, 0, 0, 0, 0, 0, 0},
                                {5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {6, 2, 8, 4, 0, 0, 0, 0, 0, 0},
                                {7, 4, 1, 8, 5, 2, 9, 6, 3, 0},
                                {8, 6, 4, 2, 0, 0, 0, 0, 0, 0},
                                {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    cin >> q;
    while (q--) {
        long long n, m;
        cin >> n >> m;
        long long numDivisors = n / m;
        if (m % 10 == 0)
            cout << "0\n";
        else if (m % 10 == 5)
            cout << 5 * (numDivisors % 2 == 0 ? numDivisors / 2 : numDivisors / 2 + 1) << "\n";
        else if (m % 2 == 0) {
            long long ret = (numDivisors / 5) * 20;
                for (int i=0; i<numDivisors%5; i++)
                    ret += lastDigit[m%10][i];
            cout << ret << "\n";
        } else {
            long long ret = (numDivisors / 10) * 45;
                for (int i=0; i<numDivisors%10; i++)
                    ret += lastDigit[m%10][i];
            cout << ret << "\n";
        }
    }

    return 0;
}