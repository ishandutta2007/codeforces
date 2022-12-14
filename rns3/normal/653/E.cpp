#include<stdio.h>
#include<set>
#include<vector>
#include<queue>
using namespace std;
#define N 301000

vector<int> v[N];
struct dat{
    int x, val;
    dat(int x=0, int val=0):x(x), val(val){}
};

int n;

bool operator < (dat a, dat b){
    if(a.val != b.val) return a.val > b.val;
    return a.x < b.x;
}

set<dat> S;
set<dat> :: iterator it, it1;
int deg[N];
bool vis[N];
int doit(int st){
    int cnt = 0;
    S.clear();
    for(int i=st; i<=n; i++){
        dat A = dat(i, n-st);
        S.insert(A);
    }
    for(int i=st; i<=n; i++)deg[i] = n-st;
    for(int i=st; i<=n; i++)vis[i] = false;
    int num = 0;
    while(!S.empty()){
        it = S.begin();
        dat A = *it;
        S.erase(it);
        if(A.val == n-st-num)cnt++;
        int i = A.x;
        for(int j=0; j<v[i].size(); j++){
            int k = v[i][j];
            if(k<st || vis[k])continue;
            int x = deg[k];
            dat B = dat(k, x);
            it1 = S.find(B);
            S.erase(it1);
            deg[k]--;
            B = dat(k, deg[k]);
            S.insert(B);
        }
        vis[i] = true;
        num++;
    }
    return cnt;
}


int main(){
    //freopen("1.in", "r", stdin);
    int m, K, x, y;
    scanf("%d%d%d", &n, &m, &K);
    for(int i=0; i<m; i++)scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
    if(v[1].size()+K>=n || doit(1)>1){
        puts("impossible");
        return 0;
    }
    if(doit(2)>K){
        puts("impossible");
        return 0;
    }
    puts("possible");
    return 0;
}