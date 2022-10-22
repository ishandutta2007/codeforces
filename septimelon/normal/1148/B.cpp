#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k, t, t2;
    int cura, curb, cur;
    cin >> n >> m >> t >> t2 >> k;
    vector<long long> a(n);
    vector<long long> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += t;
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    /*reverse(b.begin(), b.end());
    curb = b.size()-1;
    while (curb >= 0 && b[curb] < a[0]) {
        b.pop_back();
        curb--;
        m--;
    }
    reverse(b.begin(), b.end());*/
    if (k >= min(n, m)) {
        cout << "-1" << endl;
        return 0;
    }
    b.push_back(2000000002);
    cura = k-1;
    curb = 0;
    long long maxtime;
    cur = 0;
    //cout << a[k] << endl;
    while (b[cur] < a[cura+1])
        cur++;
    if (b[cur] == 2000000002) {
        cout << "-1" << endl;
        return 0;
    }
    maxtime = b[cur]+t2;
    for (int q = 0; q < k; q++) {
        cura--;
        curb++;
        while (b[cur] >= a[cura+1] && cur >= 0)
            cur--;
        //cout << a[cura+1] << " " << b[cur] << " " << b[cur+1] << endl;
        cur++;
        cur += curb;
        if (cur >= b.size() - 1) {
            cout << "-1" << endl;
            return 0;
        }
        maxtime = max(b[cur]+t2, maxtime);
        cur -= curb;
    }
    cout << maxtime << endl;
    return 0;
}