#include <bits/stdc++.h>
using namespace std;

int bitMx[1000002] = {}, bitMn[1000002] = {};

int queryMx(int x) {
    int ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret += bitMx[i];
    return ret;
}

void updateMx(int x) {
    for (int i=x; i<=1000001; i+=i&-i)
        bitMx[i]++;
}

int queryMn(int x) {
    int ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret += bitMn[i];
    return ret;
}

void updateMn(int x) {
    for (int i=x; i<=1000001; i+=i&-i)
        bitMn[i]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long long ret = 0;
    for (int i=0; i<n; i++) {
        int l;
        bool assent = false;
        vector<int> seq;
        cin >> l;
        while (l--) {
            int s;
            cin >> s;
            if (!seq.empty() && s > seq.back())
                assent = true;
            seq.push_back(s);
        }
        if (!assent) {
            updateMx(seq[0] + 1);
            updateMn(seq.back() + 1);
            ret += queryMx(seq.back() + 1) + queryMn(1000001) - queryMn(seq[0]) - (seq[0] == seq.back());
        }
    }

    cout << (long long) n * n - ret << "\n";

    return 0;
}