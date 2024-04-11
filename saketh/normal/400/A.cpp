#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T;
    for (cin >> T; T; T--) {
        string cards;
        cin >> cards;

        vector<string> ways;
        for (int a = 1; a <= 12; a++) {
            if(12 % a) continue;
            int b = 12 / a;

            bool works = false;
            for (int c = 0; c < b; c++) {
                bool good = true;
                for (int r = 0; r < a; r++) 
                    good &= cards[r * b + c] == 'X';
                works |= good;
            }

            stringstream ss;
            ss << a << "x" << b;
            if (works) ways.push_back(ss.str());
        }

        cout << ways.size() << " ";
        for (string str : ways) cout << str << " ";
        cout << "\n";
    }
}