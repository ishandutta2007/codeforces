#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
#define N 121000

vector<int> v[N], rv[N];

struct dat{
    int pos, x, y, z;
    dat(int pos=0, int x=0, int y=0, int z=0):pos(pos), x(x), y(y), z(z){}
}p[N];

bool vis[N];
int deg[N];

bool operator < (dat a, dat b){
    if(a.pos!=b.pos)return a.pos< b.pos;
}

set<int> s;
set<int> :: iterator it;

bool find(int i){
    if(s.find(i)!=s.end())return 1;
    return 0;
}


int main(){
    int n;
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=4*n; i++)scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z), p[i].pos = i, v[p[i].x].push_back(i), rv[p[i].y].push_back(i), rv[p[i].z].push_back(i);
    for(int i=1; i<=4*n; i++)vis[i] = false;
    for(int i=1; i<=n; i++)deg[i] = 4;
    puts("YES");
    for(int i=1; i<=4*n; i++)s.insert(i);
    int cnt = 0;
    while(cnt<4*n){
        if(s.empty())break;
        it = s.begin();
    
        int pos= *it;
        int x = p[pos].x;
        int y = p[pos].y;
        int z = p[pos].z;
        s.erase(it);
        if(vis[pos])continue;
        vis[pos] = true;
        cnt++;
        printf("%d ", pos);
        deg[x]--;
        deg[y]++;
        deg[z]++;
        for(int i=0; i<rv[x].size(); i++){
            int j = rv[x][i];
            if(vis[j])continue;
            int y1 = p[j].y;
            int z1 = p[j].z;
            int x1 = p[j].x;
            deg[x1]--;
            deg[y1]++;
            deg[z1]++;
            if(deg[y1]<=9 && deg[z1]<=9){
                if(!find(j))s.insert(j);
            }else {
                if(find(j))s.erase(j);
            }
            deg[x1]++;
            deg[y1]--;
            deg[z1]--;
        }
        for(int i=0; i<rv[y].size(); i++){
            int j = rv[y][i];
            if(vis[j])continue;
            int y1 = p[j].y;
            int z1 = p[j].z;
            int x1 = p[j].x;
            deg[x1]--;
            deg[y1]++;
            deg[z1]++;
            if(deg[y1]<=9 && deg[z1]<=9){
                if(!find(j))s.insert(j);
            }else {
                if(find(j))s.erase(j);
            }
            deg[x1]++;
            deg[y1]--;
            deg[z1]--;
        }
        for(int i=0; i<rv[z].size(); i++){
            int j = rv[z][i];
            if(vis[j])continue;
            int y1 = p[j].y;
            int z1 = p[j].z;
            int x1 = p[j].x;
            deg[x1]--;
            deg[y1]++;
            deg[z1]++;
            if(deg[y1]<=9 && deg[z1]<=9){
                if(!find(j))s.insert(j);
            }else {
                if(find(j))s.erase(j);
            }
            deg[x1]++;
            deg[y1]--;
            deg[z1]--;
        }

    }

    return 0;
}