#include <bits/stdc++.h>
using namespace std;

int T, d;
char str[1010101];
char A[1010101], B[1010101];
char K[30];
bool chk[30];

bool f(int k, bool L, bool H){
    if ((L && H) || !str[k]) return true;
    if (K[str[k]-'a']){
        if (K[str[k]-'a'] < A[k] && !L) return false;
        if (K[str[k]-'a'] > B[k] && !H) return false;
        return f(k+1, (A[k]<K[str[k]-'a'] || L), (B[k]>K[str[k]-'a'] || H));
    }
    for (char i=(L ? 'a' : A[k]); i<=(H ? 'a'+d-1 : B[k]); i++){
        if (chk[i-'a']) continue;
        chk[i-'a'] = true;
        K[str[k]-'a'] = i;
        if (f(k+1, (A[k]<i || L), (B[k]>i || H))) return true;
        K[str[k]-'a'] = 0;
        chk[i-'a'] = false;
    }
    return false;
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &d);
        scanf("%s", str+1);
        scanf("%s", A+1);
        scanf("%s", B+1);
        memset(K, 0, sizeof K);
        memset(chk, false, sizeof chk);
        if (f(1, false, false)){
            puts("YES");
            for (int i=0; i<d; i++){
                if (!K[i]) {
                    for (int j=0; j<d; j++){
                        if (!chk[j]){
                            K[i] = 'a' + j;
                            chk[j] = true;
                            break;
                        }
                    }
                }
                printf("%c", K[i]);
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}