#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e6;

char s[N];
int n, m, q, j, k = -1, nxt[N] = {-1}, advnxt[N][26];

void init(){
	while(s[j] != '\0'){
		if(k == -1 || s[j] == s[k])
			nxt[++j] = ++k;
		else
            k = nxt[k];
	}
}

void solve(int j, int k){
    while(s[j] != '\0'){
        if(k == -1 || s[j] == s[k])
            nxt[++j] = ++k;
        else if(k < n)
            k = advnxt[k][s[j] - 'a'];
        else
            k = nxt[k];
    }
}

int main(){
    scanf("%s%d", s, &q);
    n = strlen(s);
    init();
    for (int i = 0; i < 26; i++)
        advnxt[0][i] = -1;
    advnxt[0][s[0] - 'a'] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 26; j++)
            advnxt[i][j] = advnxt[nxt[i]][j];
        advnxt[i][s[i] - 'a'] = i;
    }
    while(q--){
        scanf("%s", s + n);
        solve(j, k);
        for (int i = n; s[i]; i++)
            printf("%d ", nxt[i + 1]);
        putchar('\n');
    }
    return 0;
}