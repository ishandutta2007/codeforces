#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;


void solve() {

}

int main() {
    //  ios_base::sync_with_stdio(0);
//  cin.tie(0);

    int n, q;
    cin >> n >> q;

    int cnt = 0;
    vector<vector<bool>> b(2, vector<bool>(n, false));
    for(int ind = 0; ind < q; ind++) {
        int i, j;
        cin >> i >> j;

        i--;
        j--;

        int i1 = i ^ 1;
        vector<int> j1;
        for(int x = j - 1; x <= j + 1; x++)
            if(x >= 0 && x < n)
                j1.push_back(x);

        if(b[i][j]) {
            for(auto j2 : j1)
                if(b[i1][j2])
                    cnt--;
            b[i][j] = 0;
        } else {
            for(auto j2 : j1)
                if(b[i1][j2])
                    cnt++;
            b[i][j] = 1;
        }

        cout << (cnt > 0 ? "No" : "Yes") << endl;
    }
}