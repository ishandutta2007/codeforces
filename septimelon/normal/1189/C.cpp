#include <bits/stdc++.h>

using namespace std;

int sum[500000];

int check(int l, int r, int ind, int sl, int sr) {
    if (l == sl && r == sr) {
        //cout << l << "-" << r << ";";
        return sum[ind];
    }
    if (sl < (l+r)/2 && sr > (l+r)/2) {
        //cout << "(" << l << "," << r << "," << sl << "," << sr << ")";
        return check(l, (l+r)/2, ind*2+1, sl, (l+r)/2) + check((l+r)/2, r, ind*2+2, (l+r)/2, sr);
    }
    if (sl < (l+r)/2) {
        //cout << "left;";
        return check(l, (l+r)/2, ind*2+1, sl, sr);
    }
        //cout << "right;";
    return check((l+r)/2, r, ind*2+2, sl, sr);
}

int main()
{
    int n, inti;
    vector<int> s;
    for (int i = 0; i < 500000; i++)
        sum[i] = 0;
    cin >> n;
    int l, r, ind;
    for (int i = 0; i < n; i++) {
        cin >> inti;
        s.push_back(inti);
        l = 1;
        r = n+1;
        ind = 0;
        while (r - l > 1) {
            sum[ind] += inti;
            if (i+1 >= (l+r)/2) {
                l = (l+r)/2;
                ind = ind * 2 + 2;
            }
            else {
                r = (l+r)/2;
                ind = ind * 2 + 1;
            }
        }
        sum[ind] = inti;
    }
    int q;
    int indl, indr;
    cin >> q;
    for (int qqq = 0; qqq < q; qqq++) {
        cin >> l >> r;
        r++;
        cout << check(1, n+1, 0, l, r)/10 << endl;
    }
    /*for (int i = 0; i < 4*n; i++)
        cout << sum[i] << " ";
    cout << endl;*/
    return 0;
}