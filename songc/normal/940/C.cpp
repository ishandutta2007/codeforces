#include <bits/stdc++.h>
using namespace std;

int N, k;
bool s[30];
char S[101010], T[101010], m = 'z'+1, M;

int main() {
    scanf("%d %d", &N, &k);
    scanf("%s", S);
    for (int i=0; i<N; i++){
        s[S[i]-'a'] = true;
        m = min(m, S[i]);
        M = max(M, S[i]);
        T[i] = S[i];
    }
    if (N < k){
        printf("%s", S);
        for (int i=0; i<k-N; i++) printf("%c", m);
        return 0;
    }
    for (int i=k-1; i>=0; i--){
        if (T[i] != M) {
            for (int j=T[i]-'a'+1; j<30; j++){
                if (s[j]){
                    T[i] = j+'a';
                    break;
                }
            }
            break;
        }
        else T[i] = m;
    }
    for (int i=0; i<k; i++) printf("%c", T[i]);
    return 0;
}