#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<ii> moves;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ii> rem;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x) rem.push_back({x, i});
    }
    sort(rem.rbegin(), rem.rend());
    if(rem.size() <= 1) {
        cout << "-1\n";
        return 0;
    }
    while(rem.size() >= 3) {
        int sz = rem.size() - 1;
        vector<ii> red = {rem[sz], rem[sz - 1], rem[sz - 2]};
        while(red.size() >= 3) {
            sort(red.begin(), red.end());
            int A = red[0].first, B = red[1].first, C = red[2].first;
            //cout << red[0].second << " " << red[1].second << " " << red[2].second << endl;
            //cout << A << "   " << B << "   " << C << endl;

            int R = B / A;
            for(int p = 1; p <= R; p <<= 1) {
                if(p & R) {
                    B -= A;
                    moves.push_back({red[1].second, red[0].second});
                }
                else {
                    C -= A;
                    moves.push_back({red[2].second, red[0].second});
                }
                A <<= 1;
            }
            if(B == 0) {
                //cout << "eliminated " << red[1].second << endl;
                red = {{A, red[0].second}, {C, red[2].second}};
            }
            else red = {{A, red[0].second}, {B, red[1].second}, {C, red[2].second}};
        }
        rem.pop_back();
        rem.pop_back();
        rem.pop_back();
        rem.push_back(red[0]);
        rem.push_back(red[1]);
    }
    cout << moves.size() << '\n';
    for(auto p : moves)
        cout << p.second << " " << p.first << '\n';
}