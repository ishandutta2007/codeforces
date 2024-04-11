#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map <string, int> mp;

char s[37][3], t[37];
char ss[7];
int n, q;
int tot;

void dfs(int len){
    if(len == n){
        if(!mp[ss]) mp[ss] = ++tot;

        return ;
    }
    for(int i=0; i<q; i++) if(t[i] == ss[len-1]) {
        char tmp = ss[len-1];
        ss[len-1] = s[i][1], ss[len] = s[i][0];
        dfs(len+1);
        ss[len-1] = tmp;
    }
}

int main(){
    //freopen("b.in", "r", stdin);
    mp.clear();
    tot = 0;
    scanf("%d %d", &n, &q);
    for(int i=0; i<q; i++){
        scanf("%s %c", s[i], &t[i]);
    }
    ss[n] = NULL;
    ss[0] = 'a';
    dfs(1);
    printf("%d\n", tot);
    return 0;
}