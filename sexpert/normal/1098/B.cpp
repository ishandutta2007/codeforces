#include <bits/stdc++.h>
using namespace std;

string ls = "ACGT";
vector<string> perms = {"AGCT", "ACTG", "ATCG", "CGAT", "CTAG", "GTAC"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for(int i = 0; i < n; i++)
        cin >> board[i];
    int mcoin = 0;
    string mperm, mbld;
    char mtype;
    for(string perm : perms) {
        int coin = 0;
        string bld = "";
        for(int i = 0; i < n; i++) {
            int rcoin1 = 0, rcoin2 = 0;
            for(int j = 0; j < m; j++) {
                if(board[i][j] == perm[2*(i % 2) + (j % 2)])
                    rcoin1++;
                if(board[i][j] == perm[2*(i % 2) + ((j + 1) % 2)])
                    rcoin2++;
            }
            if(rcoin1 > rcoin2) {
                bld += '0';
                coin += rcoin1;
            }
            else {
                bld += '1';
                coin += rcoin2;
            }
        }
        if(coin > mcoin) {
            mcoin = coin;
            mperm = perm;
            mbld = bld;
            mtype = 'H';
        }
        coin = 0;
        bld = "";
        for(int j = 0; j < m; j++) {
            int ccoin1 = 0, ccoin2 = 0;
            for(int i = 0; i < n; i++) {
                if(board[i][j] == perm[2*(j % 2) + (i % 2)])
                    ccoin1++;
                if(board[i][j] == perm[2*(j % 2) + ((i + 1) % 2)])
                    ccoin2++;
            }
            if(ccoin1 > ccoin2) {
                bld += '0';
                coin += ccoin1;
            }
            else {
                bld += '1';
                coin += ccoin2;
            }
        }
        if(coin > mcoin) {
            mcoin = coin;
            mperm = perm;
            mbld = bld;
            mtype = 'V';
        }
    }
    if(mtype == 'H') {
        for(int i = 0; i < n; i++) {
            int off = (mbld[i] == '0' ? 0 : 1);
            for(int j = 0; j < m; j++)
                board[i][j] = mperm[2*(i%2) + ((j + off)%2)];
        }
    }
    if(mtype == 'V') {
        for(int j = 0; j < m; j++) {
            int off = (mbld[j] == '0' ? 0 : 1);
            for(int i = 0; i < n; i++)
                board[i][j] = mperm[2*(j%2) + ((i + off)%2)];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << board[i][j];
        cout << endl;
    }
}