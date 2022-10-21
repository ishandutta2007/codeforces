#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef long long ll;

int n, k;
char s[N];
int g[N];
ll fre[30];
int sz;

int main(){
    scanf("%s", s);
    scanf("%d", &k);

    n = strlen(s);

    if(1LL * n * (n+1) / 2 < k) return !printf("No such line.");

    for(int i = 0; i < n; i++) g[i] = i;
    sz = n;


    while(k > 0){
        fill(fre, fre+26, 0);
        for(int i = 0; i < sz; i++) fre[s[g[i]]-'a'] += n - g[i];
        int t;
        for(t = 0; t < 26; t++){
            if(k <= fre[t]) break;
            else k -= fre[t];
        }
        printf("%c", (char)(t + 'a'));

        int nsz = 0;
        for(int i = 0; i < sz; i++){
            if(s[g[i]] - 'a' == t){
                k--;
                if(g[i] + 1 < n) g[nsz++] = g[i]+1;
            }
        }
        sz = nsz;
    }
}