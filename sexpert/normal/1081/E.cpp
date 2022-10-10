#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> guys;
    vector<long long> seq;
    for(int i = 0; i < n/2; i++) {
        int x;
        cin >> x;
        guys.push_back(x);
    }
    for(int i = 0; i < n/2; i++) {
        if(guys[i] % 4 == 2) {
            cout << "No\n";
            return 0;
        }
    }
    // Possibly make this faster
    // Fancify this
    for(int i = 0; i < n/2; i++) {
        int m = guys[i];
        pair<int, int> best;
        for(int d = 1; d * d < m; d++) {
            if(m % d)
                continue;
            if(d % 2 == (m/d)%2) {
                if(!seq.empty() && (m/d - d)/2 <= seq.back())
                    break;
                best = {d, m/d};
            }
        }
        //cout << m << " " << best.first << " " << best.second << endl;
        seq.push_back((best.second - best.first)/2);
        seq.push_back((best.second + best.first)/2);
    }
    /*for(auto x : seq)
        cout << x << " ";
    cout << endl;*/
    for(int i = 0; i < n - 1; i++) {
        if(seq[i + 1] <= seq[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    cout << seq[0] * seq[0] << " ";
    for(int i = 0; i < n - 1; i++) {
        cout << seq[i + 1]*seq[i + 1] - seq[i]*seq[i] << " ";
    }
    cout << endl;
}