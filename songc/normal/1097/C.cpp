#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int ans;
map<int, int> cnt;
char str[505050];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%s", str+1);
        int k = 0;
        bool a = true, b = true;
        for (int i=1; str[i]; i++){
            if (str[i] == '(') k++;
            else k--;
            if (k < 0) a = false;
        }
        k = 0;
        for (int i=strlen(str+1); i>0; i--) {
            if (str[i] == '(') k++;
            else k--;
            if (k > 0) b = false;
        }
        if (k >= 0 && !a) continue;
        if (k <= 0 && !b) continue;
        if (cnt[-k]){
            ans++;
            cnt[-k]--;
        }
        else cnt[k]++;
    }
    printf("%d\n", ans);
    return 0;
}