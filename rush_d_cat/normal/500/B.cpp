#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=302;
vector<int> vec[N];
int n,p[N],ans[N]; char a[N][N]; 
int par[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}

int main(){
    for(int i=0;i<N;i++)par[i]=i;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) {
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]=='1') par[find(i)]=find(j);

    for(int i=1;i<=n;i++) {
        vec[find(i)].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        vector<int> tmp;
        if(vec[i].size()) {
            for(auto x: vec[i]) {
                //printf("%d ", x);
                tmp.push_back(p[x]);
            } //printf("\n");
            sort(tmp.begin(),tmp.end());
            for(int j=0;j<tmp.size();j++){
                ans[vec[i][j]] = tmp[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ", ans[i]);
}