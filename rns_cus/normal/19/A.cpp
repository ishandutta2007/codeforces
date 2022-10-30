#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 100

map <string, int> mp;

char s[N][N], txt[N], *token, *G[10];
int mark[N], n, mg[N], sg[N], m, x, y, mx, my, id[N];

bool cmp(int x, int y){
    if(mark[x]!= mark[y]) return mark[x] > mark[y];
    if(mg[x] != mg[y]) return mg[x] > mg[y];
    else return sg[x] >= sg[y];
}
bool cmp1(int x, int y){
    return strcmp(s[x], s[y]) < 0;
}

int main(){
    gets(txt);
    n = atoi(txt);
    for(int i = 0; i < n; i ++){
        gets(s[i]);
        mp[s[i]] = i;
        id[i] = i;
    }
    m = n * (n - 1) / 2;
    for(int i = 0; i < m; i ++){
        gets(txt);
        int k = 0;
        for(token = strtok(txt, " :-"); token != NULL; token = strtok(NULL," :-")){
            G[k++] = token;
        }
        x = mp[G[0]];
        y = mp[G[1]];
        mx = atoi(G[2]);
        my = atoi(G[3]);
        mg[x] += (mx - my);
        mg[y] += (my - mx);
        sg[x] += mx;
        sg[y] += my;
        if(mx > my) { mark[x] += 3; }
        else if(mx < my) { mark[y] += 3; }
        else { mark[x] ++; mark[y] ++; }
    }
    sort(id, id + n, cmp);
    sort(id, id + (n / 2), cmp1);
    for(int i = 0; i < (n/2); i ++){
        puts(s[id[i]]);
    }
}