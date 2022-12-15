#include <bits/stdc++.h>

using namespace std;

int n, cnt0[3]{0, 0, 0}, cnt1[3]{0, 0, 0};
string s[3];

void solve2(int i, int j, int x){
    string curr = "";
    int ptr_i = 0, ptr_j = 0;
    while(ptr_i < 2 * n && ptr_j < 2 * n){
        if(s[i][ptr_i] != ('0' + x)){
            curr += s[i][ptr_i++];
            continue;
        }
        if(s[j][ptr_j] != ('0' + x)){
            curr += s[j][ptr_j++];
            continue;
        }
        curr += '0' + x;
        if(s[i][ptr_i] == '0' + x) ++ptr_i;
        if(s[j][ptr_j] == '0' + x) ++ptr_j;
    }
    while(ptr_i != 2 * n) curr += s[i][ptr_i++];
    while(ptr_j != 2 * n) curr += s[j][ptr_j++];
    cout << curr << "\n";
    return;
}

void solve(){
    fill(cnt0, cnt0 + 3, false);
    fill(cnt1, cnt1 + 3, false);

    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; ++i)
        for(char c: s[i]){
            if(c == '0') ++cnt0[i];
            else ++cnt1[i];
        }

    int i1, i2;
    for(int i = 0; i < 3; ++i)
        for(int j = i + 1; j < 3; ++j){
            if(min(cnt0[i], cnt0[j]) >= n){
                solve2(i, j, 0);
                return;
            }
            if(min(cnt1[i], cnt1[j]) >= n){
                solve2(i, j, 1);
                return;
            }
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}