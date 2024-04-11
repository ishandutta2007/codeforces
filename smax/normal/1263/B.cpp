#include <bits/stdc++.h>
using namespace std;

string p[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> p[i];

        int ret = 0;
        for (int i=0; i<n; i++) {
            int digit = 0;
            string orig = p[i];
            bool change = false;
            for (int j=0; j<n; j++)
                if (i != j && p[i] == p[j]) {
                    change = true;
                    bool done = false;
                    while (!done) {
                        done = true;
                        p[i][digit]++;
                        if (p[i][digit] > '9')
                            p[i][digit] = '0';
                        if (p[i][digit] == orig[digit]) {
                            digit++;
                            p[i][digit]++;
                            if (p[i][digit] > '9')
                                p[i][digit] = '0';
                        }
                        for (int k=0; k<n; k++)
                            if (k != i && p[k] == p[i])
                                done = false;
                    }
                }
            ret += change;
        }

        cout << ret << "\n";
        for (int i=0; i<n; i++)
            cout << p[i] << "\n";
    }

    return 0;
}