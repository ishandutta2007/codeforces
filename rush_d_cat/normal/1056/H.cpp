#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
const int N = 300000 + 10;
const int INF = 1e9 + 7;

int t,n,q;
vector<int> v[N];
int pos[N];
vector< pair<int,int> > L[N];
int mp[N],T[N];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&q);
        int tot=0;
        for(int i=1;i<=q;i++)v[i].clear();for(int i=1;i<=n;i++)L[i].clear(); 
        for(int i=1;i<=max(n,q);i++)pos[i]=0,T[i]=0;

        for(int i=1;i<=q;i++){
            int k; scanf("%d",&k);tot+=k;
            for(int j=1;j<=k;j++){
                int x; scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        int R=sqrt(tot); bool ok=1;
        for(int i=1;i<=q;i++){
            if(v[i].size()>=R){
                for(int j=1;j<=n;j++)pos[j]=INF;
                for(int j=0;j<v[i].size();j++)pos[v[i][j]]=j;
                for(int j=1;j<=q;j++){
                    if(i==j)continue;
                    int mn=INF;
                    for(int x=0;x<(int)v[j].size();x++){
                        if(pos[v[j][x]] <= mn) {
                            mn = pos[v[j][x]];
                        } else {
                            if(pos[v[j][x]] != pos[v[j][x-1]] + 1 && pos[v[j][x]]!=INF) {
                                ok=0;
                            }
                        }
                    }
                }
            } else {
                for(int x=0;x<(int)v[i].size()-1;x++){
                    for(int y=x+1;y<v[i].size();y++){
                        L[v[i][x]].push_back(make_pair(v[i][y],v[i][x+1]));
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(auto p:L[i]){
                if(T[p.first]!=i){
                    T[p.first]=i, mp[p.first]=p.second;
                } else {
                    if(mp[p.first] != p.second) ok = 0;
                }
            }
        }
        printf("%s\n", ok?"Robot":"Human");
    }
}