#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 100000
#define INF 2000000000

int N;
int p[MAX_N+1];
vector<int> gp[MAX_N+1];
int lv[MAX_N+1];
int s[MAX_N+1];

void dfs(int x){
    for(int j=0; j<gp[x].size(); j++){
        lv[gp[x][j]]=lv[x]+1;
        dfs(gp[x][j]);
    }
}

int sum=0;
bool tf=true;

int a[MAX_N+1];
int t;


void dfs2(int x){
    if(s[x]==-1){
        t=s[p[x]];
        a[x]=INF;
        for(int i=0; i<gp[x].size(); i++){
            if(s[gp[x][i]]<t){
                tf=false; return;
            }
            a[x]=min(s[gp[x][i]]-t, a[x]);
        }
        if(gp[x].size()==0){
            a[x]=0;
        }
        s[x]=s[p[x]]+a[x];
    }else{
        if(x!=1)   {
            a[x]=s[x]-s[p[x]];
            if(s[p[x]]>s[x]){
                tf=false;
                return;
            }
        }else  a[x]=s[x];
    }
    for(int i=0; i<gp[x].size(); i++){
        dfs2(gp[x][i]);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=2; i<=N; i++){
        scanf("%d", &p[i]);
        gp[p[i]].push_back(i);
    }
    for(int i=1; i<=N; i++){
        scanf("%d", &s[i]);
    }
    lv[1]=1;
    dfs(1);
    for(int i=1; i<=N; i++){
        if(lv[i]%2==0 && s[i]!=-1){
            printf("-1"); return 0;
        }
        else if(lv[i]%2==1 && s[i]==-1){
            printf("-1"); return 0;
        }
    }
    dfs2(1);
    if(tf){
        long long ans=0;
        for(int i=1; i<=N; i++){
            ans+=(long long)a[i];
        }
        printf("%lld", ans);
    }else{
        printf("-1");
    }
    return 0;
}