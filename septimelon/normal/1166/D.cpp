#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    long long a, b, m, x[100];
    long long delta[100];
    long long mi, ma;
    cin >> q;
    int len, l2;
    long long cha;
    for (int k = 0; k < q; k++) {
        cin >> a >> b >> m;
        if (a == b) {
            cout << "1 " << a << endl;
            continue;
        }
        len = 1; ///last element index
        x[0] = a;
        mi = a + 1;
        ma = a + m;
        while (ma < b) {
            mi *= 2;
            ma *= 2;
            len++;
        }
        if (mi > b) {
            cout << "-1" << endl;
            continue;
        }
        x[len] = b;
        if (len > 1) {
        ma = 1;
        for (int i = 0; i < len-2; i++)
            ma *= 2;
        for (int i = 0; i < len-2; i++) {
            if ((b-mi)/ma >= m)
                delta[i] = m-1;
            else
                delta[i] = (b-mi)/ma;
            b -= delta[i]*ma;
            delta[i]++;
            ma /= 2;
            //cout << b << endl;
        }
        if (b-mi < m) {
            delta[len-2] = b-mi+1;
        }
        else
            delta[len-2] = m;
        x[1] = x[0]+delta[0];
        for (int i = 2; i < len; i++) {
            x[i] = x[i-1]*2-delta[i-2]+delta[i-1];
        } }
        /*for (int l2 = 1; l2 < len; l2++) {
            cha = 0;
            b /= 2;
            x[len-l2] = b;
        }*/
        cout << len+1;
        for (int i = 0; i <= len; i++) {
            cout << " " << x[i];
        }
        cout << endl;
    }
    return 0;
}