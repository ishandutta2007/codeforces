#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


bool check (vector<int> &v, int n, int &L, int &R) {
    L = 0;
    R = n-1;
    while (R-L+1 >= 3) {
        if (abs(v[L]-v[R]) >= R-L+1) return true;
        int d1 = abs(v[L]-v[L+1]);
        int d2 = abs(v[R]-v[R-1]);
        if (d1 < d2) {
            L++;
        }
        else {
            R--;
        }
    }
    return (abs(v[L]-v[R]) >= R-L+1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (int i =0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        int L, R;
        if (check(v, n, L, R)) {
            cout << "YES" << endl;
            cout << L+1 << " " << R+1 << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
	exit(0);
}