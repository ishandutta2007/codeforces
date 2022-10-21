#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int q, slen, tlen;
string S, T;
int s[N], t[N];
int sla[N], tla[N];

int solve(int a, int b, int c, int d) {
    int cnt_S_a = b - max(sla[b] + 1, a) + 1;
    int cnt_S_b = s[b] - s[a-1];
    int cnt_T_a = d - max(tla[d] + 1, c) + 1;
    int cnt_T_b = t[d] - t[c-1];
    if((cnt_S_b - cnt_T_b) % 2 != 0 || cnt_S_b > cnt_T_b) return 0;
    if(cnt_S_a < cnt_T_a) return 0;
    if(cnt_S_b == cnt_T_b) {
        if((cnt_S_a - cnt_T_a) % 3 == 0) return 1;
        else return 0;
    }
    else {
        if(cnt_S_b == 0) return cnt_S_a > cnt_T_a;
        else return 1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> T;
    slen = S.length();
    tlen = T.length();
    S = " " + S;
    T = " " + T;
    int la = 0;
    for(int i = 1; i <= slen; i++) {
        s[i] = s[i-1] + (S[i] != 'A');
        if(S[i] != 'A') la = i;
        sla[i] = la;
    }
    la = 0;
    for(int i = 1; i <= tlen; i++) {
        t[i] = t[i-1] + (T[i] != 'A');
        if(T[i] != 'A') la = i;
        tla[i] = la;
    }
//    for(int i = 1; i <= slen; i++) cout << s[i];
//    cout << endl;
//    for(int i = 1; i <= slen; i++) cout << sla[i];
//    cout << endl;
//    for(int i = 1; i <= tlen; i++) cout << t[i];
//    cout << endl;
//    for(int i = 1; i <= tlen; i++) cout << tla[i];
//    cout << endl;
    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d);
    }

}