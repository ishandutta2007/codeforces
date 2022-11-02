#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, k, fi, maxi[N], mini[N], fl[N];
bool flg = 1;
char s[N], t1[N], t2[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d\n", &n, &k);
    gets(s + 1);
    for (int i = 1; i <= n; i ++) {
        t1[i] = t2[i] = s[i];
        if (s[i] == 'W') {
            if (i < n && maxi[i-1] == k - 1) fl[i] = 1, maxi[i] = k - 1;
            else maxi[i] = maxi[i-1] + 1;
            mini[i] = mini[i-1] + 1;
        }
        else if (s[i] == 'D') maxi[i] = maxi[i-1], mini[i] = mini[i-1];
        else if (s[i] == 'L') {
            if (i < n && mini[i-1] == -k + 1) fl[i] = -1, mini[i] = -k + 1;
            else mini[i] = mini[i-1] - 1;
            maxi[i] = maxi[i-1] - 1;
        }
        else {
            if (i < n && maxi[i-1] == k - 1) t1[i] = 'D', maxi[i] = k - 1;
            else t1[i] = 'W', maxi[i] = maxi[i-1] + 1;
            if (i < n && mini[i-1] == -k + 1) t2[i] = 'D', mini[i] = -k + 1;
            else t2[i] = 'L', mini[i] = mini[i-1] - 1;
        }
        if (i < n && (mini[i] >= k || maxi[i] <= -k)) flg = 0;
        //cout<<mini[i]<<' '<<maxi[i]<<' '<<fl[i]<<endl;
    }
    t1[n+1] = t2[n+1] = 0;
    if (flg && mini[n] < k && maxi[n] == k) {
        for (int i = n; i >= 0; i --) {
            if (fl[i] == 1) fi ++;
            if (s[i] == '?' && fi) {
                fi --;
                if (t1[i] == 'W') t1[i] = 'D';
                else t1[i] = 'L';
                if (fi && t1[i] == 'D') t1[i] = 'L', fi--;
            }
        }
        puts(t1 + 1);
    }
    else if (flg && maxi[n] > -k && mini[n] == -k) {
        for (int i = n; i >= 0; i --) {
            if (fl[i] == -1) fi ++;
            if (s[i] == '?' && fi) {
                fi --;
                if (t2[i] == 'L') t2[i] = 'D';
                else t2[i] = 'W';
                if (fi && t2[i] == 'D') t2[i] = 'W', fi--;
            }
        }
        puts(t2 + 1);
    }
    else puts("NO");

    return 0;
}