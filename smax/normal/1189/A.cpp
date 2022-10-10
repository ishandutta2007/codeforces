#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, partialSum[100];
    string s;
    cin >> n >> s;
    partialSum[0] = s[0] == '0' ? -1 : 1;
    for (int i=1; i<n; i++)
        partialSum[i] = partialSum[i-1] + (s[i] == '0' ? -1 : 1);

    if (partialSum[n-1] != 0) {
        cout << 1 << endl << s << endl;
        return 0;
    }

    vector<int> cuts;
    for (int i=0; i<n-1; i++) {
        if (cuts.empty() && partialSum[i] != 0 || !cuts.empty() && partialSum[i] - partialSum[cuts[cuts.size()-1]] != 0) {
            cuts.push_back(i);
            if (partialSum[n-1] - partialSum[i] != 0)
                break;
        }
    }

    cout << cuts.size() + 1 << endl;
    cout << s.substr(0, cuts[0] + 1) << " ";
    for (int i=1; i<cuts.size(); i++)
        cout << s.substr(cuts[i-1] + 1, cuts[i] - cuts[i-1]) << " ";
    cout << s.substr(cuts[cuts.size()]+1) << endl;

    return 0;
}