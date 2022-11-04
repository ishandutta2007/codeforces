#include <cstdio>
using namespace std;
const int N = 1e5 + 2;

int t, n, nxt[26], fa[26];
bool vis[26];
char s[N];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
    scanf("%d", &t);
    while(t--){
        for (int i = 0; i < 26; i++){
            nxt[i] = -1;
            fa[i] = i;
            vis[i] = false;
        }
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++){
            int x = s[i] - 'a';
            if(nxt[x] != -1)
                continue;
            for (int j = 0; j < 26; j++){
                if(!vis[j] && find(x) != find(j)){
                    vis[j] = true;
                    nxt[x] = j;
                    fa[find(x)] = find(j);
                    break;
                }
            }
        }
        int cnt[26] = {}, tail = -1;
        for (int i = 0; i < 26; i++){
            if(nxt[i] != -1){
                cnt[nxt[i]]++;
            }
            else if(tail == -1){
                tail = i;
            }
            else{
                tail = -2;
            }
        }
        if(tail != -2){
            for (int i = 0; i < 26; i++)
                if(!cnt[i])
                    nxt[tail] = i;
        }
        for (int i = 1; i <= n; i++){
            s[i] = nxt[s[i] - 'a'] + 'a';
        }
        printf("%s\n", s + 1);
    }
    return 0;
}