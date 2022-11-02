#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
using namespace std;
using INT = long long;
using VI = vector<int>;
using pii = pair<int, int>;

const int NN = 111;
char s[NN][NN];
char ans[NN][NN];
int n, m, k;

inline int get(int r) {
    if(r>=k) r=k-1;
    if(r<=25) return 'a'+r;
    r-=26;
    if(r<=25) return 'A'+r;
    r -= 26;
    return r+'0';
}

int solve() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++) {
        scanf("%s", s[i]);
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cnt += s[i][j] == 'R';
    }
    int C = cnt / k;
    int re = cnt % k;
    re = k-re;


    int r=0;
    int now = 0;
    for(int i=0; i<n; i++) {
        if(i&1) {
            for(int j=0; j<m; j++) {

                if(s[i][j] == 'R') now++;
                ans[i][j] = get(r);
                if(now == C) {
                    r++;
                    if(r == re) C++;
                    now = 0;
                }
            }
        }else {
            for(int j=m-1; j>=0; j--) {
                if(s[i][j] == 'R') now++;
                ans[i][j] = get(r);
                if(now == C) {
                    r++;
                    if(r==re) C++;
                    now = 0;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) putchar(ans[i][j]);
        puts("");
    }

}



int main() {


    int T;
    cin >> T;
    while(T--) solve();
}