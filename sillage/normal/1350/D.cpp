#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int a[maxn], s[maxn];
const int inf = 2e9+200000;
int main(){
    int T, n, k;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &k);
        int flag = 0;
        for (int i = 1; i<=n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == k) flag = 1;
        }
        if (!flag){
            puts("no");
            continue;
        }
        if (n == 1){
            puts("yes");
            continue;
        }
        s[0] = 0;
        for (int i = 1; i<=n; i++){
            if (a[i] < k) s[i] = s[i-1] + 1;
            else s[i] = s[i-1];
        }
        flag = 0;
        for (int i = 1; i<=n; i++) s[i] = 2*s[i] - i; //cout<< s[i] << ' ';
        //cout << endl;
        int mx0 = s[0], mx1 = -inf;
        for (int i = 2; i<=n; i++){
            //cout << mx0 << mx1 << endl;
            if (s[i] < mx0) flag = 1;
            if (s[i] < mx1+1) flag = 1;
            if (s[i-1] > mx1) mx1 = s[i-1];
            swap(mx0, mx1);
        }
        puts(flag?"yes":"no");
    }
    return 0;
}