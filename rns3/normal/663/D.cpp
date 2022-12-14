#include <bits/stdc++.h>
using namespace std;

const int M = 5101;
const int inf = 1e9;
#define N 91

int a[M], b[M], c[M];
int sto1[M], sto2[M], sto3[M];
int d[M];
int flag[M];
int f[2][N][N][N];

int calc(int k, int n) {
    if(n < 2 * k) return 500;
    if(n < 4 * k) return 1000;
    if(n < 8 * k) return 1500;
    if(n < 16 * k) return 2000;
    if(n < 32 * k) return 2500;
    return 3000;
}

int calc1(int pt, int mi) {
    if(mi == 0) return 0;
    if(mi < 0) mi = -mi;
    return pt / 250 * (250 - mi);
}

bool ok(int bit, int id) {
    if((bit & 4) && c[id] >= 0) return 0;
    if((bit & 2) && b[id] >= 0) return 0;
    if((bit & 1) && a[id] >= 0) return 0;
    return 1;
}

void chkmin(int &aa, int bb) {
    if(aa > bb) aa = bb;
}


int main() {
    ///freopen("D.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    if(a[1] || 1) {
        for(int i = 2; i <= n; i ++) if(a[i] < 0) sto1[cnt1++] = i;
    }
    if(b[1] || 1) {
        for(int i = 2; i <= n; i ++) if(b[i] < 0) sto2[cnt2++] = i;
    }
    if(c[1] || 1) {
        for(int i = 2; i <= n; i ++) if(c[i] < 0) sto3[cnt3++] = i;
    }
    if(cnt1 + cnt2 + cnt3 >= 90) return puts("1");
    int cnt = 0;
    for(int i = 0; i < cnt1; i ++) d[cnt ++] = sto1[i];
    for(int i = 0; i < cnt2; i ++) d[cnt ++] = sto2[i];
    for(int i = 0; i < cnt3; i ++) d[cnt ++] = sto3[i];
    sort(d, d + cnt);
    cnt = unique(d, d + cnt) - d;
    for(int i = 0; i < cnt; i ++) flag[d[i]] = 1;
    int A = 0, B = 0, C = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] > 0) A ++;
        if(b[i] > 0) B ++;
        if(c[i] > 0) C ++;
    }
    int ans = n;
    for(int i = 0; i <= cnt1; i ++) if(i == cnt1 || calc(A + cnt1 - i, n) != calc(A + cnt1 - i - 1, n)){
        for(int j = 0; j <= cnt2; j ++) if(j == cnt2 || calc(B + cnt2 - j, n) != calc(B + cnt2 - j - 1, n)){
            for(int k = 0; k <= cnt3; k ++) if(k == cnt3 || calc(C + cnt3 - k, n) != calc(C + cnt3 - k - 1, n)){
                int AA = A + cnt1 - i, BB = B + cnt2 - j, CC = C + cnt3 - k;
                int aa = calc(AA, n);
                int bb = calc(BB, n);
                int cc = calc(CC, n);
                int my_pt = calc1(aa, a[1]) + calc1(bb, b[1]) + calc1(cc, c[1]) + (i + j + k) * 100;
                int rnk = 0;
                for(int r = 2; r <= n; r ++) if(!flag[r]){
                    int e_pt = calc1(aa, a[r]) + calc1(bb, b[r]) + calc1(cc, c[r]);
                    if(my_pt < e_pt) rnk ++;
                }

                bool bf = 0;
                for(int ii = 0; ii <= i; ii ++)
                    for(int jj = 0; jj <= j; jj ++)
                        for(int kk = 0; kk <= k; kk ++) f[bf][ii][jj][kk] =  inf;
                f[bf][0][0][0] = 0;
                for(int r = cnt; r; r --) {
                     for(int ii = 0; ii <= i; ii ++)
                        for(int jj = 0; jj <= j; jj ++)
                            for(int kk = 0; kk <= k; kk ++) f[bf ^ 1][ii][jj][kk] = inf;
                    for(int ii = 0; ii <= i; ii ++) {
                        for(int jj = 0; jj <= j; jj ++) {
                            for(int kk = 0; kk <= k; kk ++) if(f[bf][ii][jj][kk] != inf){
                                for(int bit = 0; bit < 8; bit ++) if(ok(bit, d[r - 1])){
                                    if(ii + ((bit & 1) > 0) > i) continue;
                                    if(jj + ((bit & 2) > 0) > j) continue;
                                    if(kk + ((bit & 4) > 0) > k) continue;
                                    int X = a[d[r-1]], Y = b[d[r-1]], Z = c[d[r-1]];
                                    if(bit & 1) X = 0;
                                    if(bit & 2) Y = 0;
                                    if(bit & 4) Z = 0;
                                    int pt = calc1(aa, X) + calc1(bb, Y) + calc1(cc, Z);
                                    chkmin(f[bf ^ 1][ii + ((bit & 1) > 0)][jj + ((bit & 2) > 0)][kk + ((bit & 4) > 0)], f[bf][ii][jj][kk] + (my_pt < pt));
                                }
                            }
                        }
                    }
                    bf = bf ^ 1;
                }
                rnk += f[bf][i][j][k];
                chkmin(ans, rnk + 1);
            }

        }
    }
    cout << ans << endl;
}