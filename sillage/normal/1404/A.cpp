#include<bits/stdc++.h>
using namespace std;
char s[300010];
int vis[300010];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n, k;
        cin >> n >> k;
        scanf("%s", s);
        bool flag = 1;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < k; i++) vis[i] = -1;
        for (int i = 0; i < n; i++){
            if (s[i] != '?') {
                if (vis[i%k] == -1) vis[i%k] = s[i], s[i] == '0' ? cnt0++ : cnt1++;
                else if (vis[i%k] != s[i]) flag = 0;
            }
        }
        if (cnt0 > k/2 || cnt1 > k/2) flag =0;
        puts(flag?"YES":"NO");
    }
    return 0;
}