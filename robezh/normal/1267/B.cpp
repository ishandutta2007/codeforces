#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> P;

int n;
vector<P> x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    for(char c : str) {

        if(x.empty() || x.back().first != c) x.push_back({c, 1});
        else x.back().second++;
    }
    n = x.size();
//    cout << x.size() << endl;
    if(n % 2 == 0) return cout << "0" << endl, 0;
    else {
        int mid = n / 2;
        if(x[mid].second < 2) return cout << "0" << endl, 0;
        for(int i = mid - 1, j = mid + 1; i >= 0; i--, j++) {
            if(x[i].first != x[j].first || x[i].second + x[j].second < 3)
                return cout << "0" << endl, 0;
        }
        cout << x[mid].second + 1 << endl;
    }
}