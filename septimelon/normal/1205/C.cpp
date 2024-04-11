#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int n;

void rev() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0)
                continue;
            a[i][j] = 1 - a[i][j];
        }
    }
}

int main()
{
    cin >> n;
    a.resize(n, vector<int>(n));
    a[0][0] = 1;
    a[n-1][n-1] = 0;
    int ans;
    cout << "? 1 1 2 2" << endl;
    fflush(stdout);
    cin >> ans;
    a[1][1] = ans;
    a[1][0] = 1;
    cout << "? 1 2 2 3" << endl;
    fflush(stdout);
    cin >> ans;
    a[2][1] = ans;
    cout << "? 2 1 2 3" << endl;
    fflush(stdout);
    cin >> ans;
    a[0][1] = (ans + 1 - a[2][1]) % 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 && i <= 1)
                continue;
            if (j == 1 && i <= 2)
                continue;
            if (j == (n-1) && j == i)
                continue;
            if (i <= 1) {
                cout << "? " << j-1 << " " << i+1 << " " << j+1 << " " << i+1 << endl;
                fflush(stdout);
                cin >> ans;
                a[i][j] = (ans + 1 - a[i][j-2]) % 2;
            }
            else {
                cout << "? " << j+1 << " " << i-1 << " " << j+1 << " " << i+1 << endl;
                fflush(stdout);
                cin >> ans;
                a[i][j] = (ans + 1 - a[i-2][j]) % 2;
            }
        }
    }
    int ind = 0;
    int ans1, ans2;
    while (a[ind+2][ind+2] == 1)
        ind += 2;
    cout << "? " << ind+1 << " " << ind+1 << " " << ind+2 << " " << ind+3 << endl;
    fflush(stdout);
    cin >> ans1;
    cout << "? " << ind+1 << " " << ind+2 << " " << ind+3 << " " << ind+3 << endl;
    fflush(stdout);
    cin >> ans2;
    if (ans1 == 1) {
        if (a[ind+2][ind+1] == 0)
            rev();
    } else if (ans2 == 1) {
        if (a[ind+1][ind] == 1)
            rev();
    } else if (a[ind+2][ind] != a[ind+1][ind+1]) {
        if (a[ind+2][ind+1] == 1)
            rev();
    } else if (a[ind+1][ind+1] == 1) {
        if (a[ind+2][ind+1] == 1)
            rev();
    } else {
        if (a[ind+1][ind] == 0)
            rev();
    }

    cout << "!";
    for (int j = 0; j < n; j++) {
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i][j];
        }
    }
    return 0;
}