#include<bits/stdc++.h>
using namespace std;

#define N 300010

char tmp[N];
string s[N];
string ans[N];
string Ans[N];

int n, m, mx = 1e9;

int calcr(int i, char a, char b) {
    int ret = 0;
    for(int j = 0; j < m; j ++) {
        char c = (j & 1) ? b : a;
        ret += (s[i][j] != c);
    }
    return ret;
}

void paintr(int i, char a, char b) {
    for(int j = 0; j < m; j ++) {
        char c = (j & 1) ? b : a;
        ans[i][j] = c;
    }
}

int calcc(int i, char a, char b) {
    int ret = 0;
    for(int j = 0; j < n; j ++) {
        char c = (j & 1) ? b : a;
        ret += (s[j][i] != c);
    }
    return ret;
}

void paintc(int i, char a, char b) {
    for(int j = 0; j < n; j ++) {
        char c = (j & 1) ? b : a;
        ans[j][i] = c;
    }
}

void solve(char a, char b, char c, char d) {
    char aa = a, bb = b, cc = c, dd = d;
    int cur = 0;
    for(int i = 0; i < m; i ++) {
        int cnt1 = calcc(i, aa, bb);
        int cnt2 = calcc(i, bb, aa);
        cur += min(cnt1, cnt2);
        if(cur >= mx) break;
        if(cnt1 > cnt2) paintc(i, bb, aa);
        else paintc(i, aa, bb);
        swap(aa, cc), swap(bb, dd);
    }
    if(cur < mx) {
        mx = cur;
        for(int i = 0; i < n; i ++) Ans[i] = ans[i];
    }
    cur = 0;
    aa = a, bb = b, cc = c, dd = d;
    for(int i = 0; i < n; i ++) {
        int cnt1 = calcr(i, aa, bb);
        int cnt2 = calcr(i, bb, aa);
        cur += min(cnt1, cnt2);
        if(cur >= mx) break;
        if(cnt1 > cnt2) paintr(i, bb, aa);
        else paintr(i, aa, bb);
        swap(aa, cc), swap(bb, dd);
    }
    if(cur < mx) {
        mx = cur;
        for(int i = 0; i < n; i ++) Ans[i] = ans[i];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", tmp), s[i] = tmp, ans[i] = tmp;
    char p[10] = "ACGT";
    for(int i = 0; i < 4; i ++) for(int j = i + 1; j < 4; j ++) {
        char a = p[i], b = p[j], c, d;
        for(int k = 0; k < 4; k ++) if(k != i && k != j) {c = p[k]; break;}
        for(int k = 3; k >= 0; k --) if(k != i && k != j) {d = p[k]; break;}
        solve(a, b, c, d);
    }
    for(int i = 0; i < n; i ++) cout << Ans[i] << endl;
}