#include <bits/stdc++.h>

#define MAX 1000000007

using namespace std;

typedef pair<int,int> pii;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n+x+y, MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i+x];
    }
    int curmin, curminind, eq;
    for (int i = 0; i < n; i++) {
        curmin = MAX;
        eq = 0;
        for (int j = 0; j <= x+y; j++) {
            if (a[i+j] < curmin) {
                curmin = a[i+j];
                curminind = i + j;
                eq = 0;
            }
            else if (a[i+j] == curmin)
                eq++;
        }
        if (curminind == i+x && eq == 0) {
            cout << curminind+1-x << endl;
            return 0;
        }
    }

    return 0;
}