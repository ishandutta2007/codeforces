#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;
    int sn = sqrt(n);
    vector<bool> lamp(n);

    while (1) {
        vector<int> ask;
        for (int i=0; i<n && ask.size()<sn; i++)
            if (i%sn && !lamp[i]) ask.push_back(i);
        if (ask.size() < sn) { cout << "0\n"; exit(0); }
        cout << sn << ' ';
        for (int i: ask) {
            lamp[i] = 1;
            cout << i+1 << ' ';
        }
        cout << endl;
        int l; cin >> l; l--;
        for (int i=0; i<sn; i++)
            lamp[(l+i) % n] = 0;
    }
}