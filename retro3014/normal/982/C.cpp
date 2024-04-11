#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 100000

int N;
vector<int> v[MAX_N+1];
int a, b;
bool visited[MAX_N+1];
int ans=0;

int DFS(int x){
    visited[x]=true;
    int sz=1;
    for(int i=0; i<v[x].size(); i++){
        if(!visited[v[x][i]]){
            sz+=DFS(v[x][i]);
        }
    }
    if(!(sz%2)){
        ans++;
        return 0;
    }
    return sz;
}




int main(){
    cin>>N;
    if(N%2){
        cout<<-1;
        return 0;
    }
    for(int i=1; i<N; i++){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    printf("%d", ans-1);
}