#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int whr(int k, const string& s){
    int n = s.length();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++){
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] != s[i])
            p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]])
            p[i]++;
        if (p[i] == k)
            return i - k;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, T;
    double c;
    cin >> n >> T >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<double> real(n), approx(n);
    real[0] = 1.0 * a[0] / T;
    approx[0] = real[0] / c;
    for (int i = 1; i < n; i++){
        int tmp = (i < T) ? 0 : a[i - T];
        real[i] = real[i - 1] + 1.0 * (a[i] - tmp) / T;
        approx[i] = (approx[i - 1] + 1.0 * a[i] / T) / c;
    }
    int m;
    cin >> m;
    cout << setprecision(10) << fixed;
    while (m--){
        int q;
        cin >> q;
        q--;
        cout << real[q] << " " << approx[q] << " " << fabs(real[q] - approx[q]) / real[q] << "\n";
    }

    return 0;
}