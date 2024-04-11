#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool fl = false;
        int sum = 0;
        int cnt = 0;
        for(auto c : s) {
            if(c == '0') {
                if(!fl)
                    fl = true;
                else
                    cnt++;
            } else {
                sum += c - '0';
                if((c - '0') % 2 == 0)
                    cnt++;
            }
        }

        if(sum % 3 == 0 && fl && cnt)
            cout << "red" << endl;
        else
            cout << "cyan" << endl;
    }
}