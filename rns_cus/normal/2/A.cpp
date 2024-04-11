#include<stdio.h>
#include<memory.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1111
#define inf 1000000000

map<string, int >mp;
int sum[N], cnt, po[N], Sum[N];
char s[N][N], ss[N][N];
int a[N];


int find(char *s){
    if(mp[s]) return mp[s];
    mp[s] = ++cnt;
    strcpy(ss[cnt], s);
    return cnt;
}

int main(){
    int n;
    //freopen("A.in","r",stdin);
    while(scanf("%d", &n) == 1) {
        int mx = -inf;
        for(int i = 1; i <= n; i ++) {
            scanf("%s%d", s[i], &a[i]);
            int id = find(s[i]);
            sum[id] += a[i];
        }
        for(int i = 1; i <= cnt; i ++) mx = max(mx, sum[i]);
        for(int i = 1; i <= n; i ++) {
            int id = find(s[i]);
            Sum[id] += a[i];
            if(Sum[id] >= mx && sum[id] >= mx){puts(s[i]);break;}
        }
    }
}