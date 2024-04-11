#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;
#define MAX_N 100000

ll N;
ll ans;
vector<int> v[MAX_N+1];

ll dv(ll a, ll b){
    if(a/b==0){
        return b/a;
    }return a/b;
}

bool visited[MAX_N+1];

void dfs(ll x, ll y){
    if(visited[x])  return;
    visited[x]=true;
    for(ll i=x*2; i<=N; i+=x){
        if(i!=y){
            ans+=i/x*4;
            dfs(i, x);
        }
        else if(i==y){
            i=0;
        }
    }
}

int main(){
    cin>>N;
    for(int i=2; i<=N; i++){
        for(int j=i*2; j<=N; j+=i){
            v[i].push_back(j);
            v[j].push_back(i);
        }
    }
    for(int i=2; i<=N; i++){
        dfs(i, 0);
    }
    cout<<ans;
    return 0;
}