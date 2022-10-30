//B
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define N 1111

struct dat{
    int id, score, f[51];
    dat(int id = 0, int score = 0) : id(id), score(score){}
}p[N];

bool cmp1(dat a, dat b){
    if(a.score != b.score) return a.score > b.score;
    for(int i = 0; i < 51; i ++) if(a.f[i] != b.f[i]) {
        return a.f[i] > b.f[i];
    }
    return a.id < b.id;
}

bool cmp2(dat a, dat b){
    if(a.f[0] != b.f[0]) return a.f[0] > b.f[0];
    if(a.score != b.score) return a.score > b.score;
    for(int i = 1; i < 51; i ++) if(a.f[i] != b.f[i]) {
        return a.f[i] > b.f[i];
    }
    return a.id < b.id;
}

const int sc[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

map <string, int> mp;

int n;
char s[N][101], t[101];

int main(){
    //freopen("bb.in", "r", stdin);
    int runs;
    scanf("%d", &runs);
    while(runs --){
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i ++){
            scanf("%s", t);
            if(!mp[t]) mp[t] = ++ n;
            int id = mp[t];
            strcpy(s[id], t);
            p[id].id = id;
            if(i < 10) p[id].score += sc[i];
            p[id].f[i] ++;
        }
    }

    sort(p + 1, p + n + 1, cmp1);
    printf("%s\n", s[p[1].id]);
    sort(p + 1, p + n + 1, cmp2);
    printf("%s\n", s[p[1].id]);
}