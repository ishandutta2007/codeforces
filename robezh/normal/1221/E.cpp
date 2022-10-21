#include <bits/stdc++.h>
using namespace std;

int n, a, b;
string str;
vector<int> ss;

void win(int sg) {
    cout << (sg ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--) {
        cin >> a >> b;
        cin >> str;
        n = str.length();
        int cur_cnt = 0;
        ss.clear();
        for(char c : str) {
            if(c == '.') cur_cnt++;
            else {
                if(cur_cnt >= b) ss.push_back(cur_cnt);
                cur_cnt = 0;
            }
        }
        if(cur_cnt >= b) ss.push_back(cur_cnt);
        sort(ss.begin(), ss.end(), greater<>());
        if(ss.empty()) {win(0); continue;}
        if(ss.back() < a) {win(0); continue;}
        if(ss.size() >= 2 && ss[1] >= 2 * b) {win(0); continue;}
        if(ss[0] < 2 * b) {win(ss.size() % 2); continue;}
        int par = (ss.size() + 1) % 2, rem = ((int)ss.size() - 1);
        int aw = 0;
        for(int bef = 0; bef + a <= ss[0]; bef++) {
            int suf = ss[0] - a - bef;
            if((bef >= 2 * b) || (bef >= b && bef < a)
                || suf >= 2 * b || (suf >= b && suf < a)) continue;
            int cnt = (par + (bef >= a) + (suf >= a));
            aw |= !(cnt % 2);
        }
//        cout << "aw: " << aw << endl;
        win(aw);
    }
}