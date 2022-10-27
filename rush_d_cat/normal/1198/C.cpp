#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=500000+10;
int T;
int n,m,vis[N],u[N],v[N];

int main(){
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=3*n;i++) vis[i]=0;
        vector<int> ans;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u[i],&v[i]); 
            if(u[i]>v[i]) swap(u[i],v[i]);
            if (i==1) {
                ans.push_back(1); vis[u[i]]=vis[v[i]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(vis[u[i]]||vis[v[i]]) continue;
            ans.push_back(i); vis[u[i]]=vis[v[i]]=1;
        }
        if(ans.size() >= n) {
            printf("Matching\n");
            for(int i=0;i<n;i++){
                printf("%d\n", ans[i]);
            }
        } else {
            printf("IndSet\n");
            int done=0;
            for(int i=1;i<=3*n;i++){
                if(vis[i]==0){
                    done++;
                    printf("%d\n", i);
                    if(done==n) break;
                }
            }
        }
    }
}