#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 50;

int n, k;
int psum[2][N], ssum[2][N];
string str;
string res[3] = {"quailty", "once again", "tokitsukaze"};

void ans(int type) {
    cout << res[type + 1] << endl;
    exit(0);
}


bool one_win(string str) {
    static int psum[2][N], ssum[2][N];
    for(int i = 1; i <= n; i++) {
        psum[0][i] = psum[0][i-1] + (str[i] == '0');
        psum[1][i] = psum[1][i-1] + (str[i] == '1');
    }
    for(int i = n; i >= 1; i--) {
        ssum[0][i] = ssum[0][i+1] + (str[i] == '0');
        ssum[1][i] = ssum[1][i+1] + (str[i] == '1');
    }
    for(int i = 1; i + k - 1 <= n; i++) {
        if((psum[0][i-1] == 0 && ssum[0][i+k] == 0) || (psum[1][i-1] == 0 && ssum[1][i+k] == 0))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> str;
    str = " " + str;
    for(int i = 1; i <= n; i++) {
        psum[0][i] = psum[0][i-1] + (str[i] == '0');
        psum[1][i] = psum[1][i-1] + (str[i] == '1');
    }
    for(int i = n; i >= 1; i--) {
        ssum[0][i] = ssum[0][i+1] + (str[i] == '0');
        ssum[1][i] = ssum[1][i+1] + (str[i] == '1');
    }
    for(int i = 1; i + k - 1 <= n; i++) {
        if((psum[0][i-1] == 0 && ssum[0][i+k] == 0) || (psum[1][i-1] == 0 && ssum[1][i+k] == 0))
            ans(1);
    }

    int have = 0;
    for(int i = 1; i + k - 1 <= n; i++) {
        if(i == 1) {
            bool win[2] = {false, false};
            string str1 = str;
            for(int j = 1; j <= k; j++) str1[j] = '0';
            if(one_win(str1)) win[0] = true;
            for(int j = 1; j <= k; j++) str1[j] = '1';
            if(one_win(str1)) win[1] = true;

            if(!win[0] || !win[1]) have = 1;
            continue;
        }
        if(i + k - 1 == n) {
            bool win[2] = {false, false};
            string str1 = str;
            for(int j = n - k + 1; j <= n; j++) str1[j] = '0';
            if(one_win(str1)) win[0] = true;
            for(int j = n - k + 1; j <= n; j++) str1[j] = '1';
            if(one_win(str1)) win[1] = true;

            if(!win[0] || !win[1]) have = 1;
            continue;
        }


        if (i - 1 > k || n - (i + k) + 1 > k) continue;

//        cout << i << endl;
        if ((psum[0][i - 1] == 0 && ssum[1][i + k] == 0) || (psum[1][i - 1] == 0 && ssum[0][i + k] == 0))
            continue;
        have = 1;
    }
    if(!have) ans(-1);
    ans(0);
}