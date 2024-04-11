#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_V = 100100;  // 

int N;  // 
vector<int> tree[MAX_V];  // 

int sizeSubtree[MAX_V];  // sizeSubtree[v] := v 
vector<int> centroids;  // 

/* DP */
void SubFindCentroids(int v, int parent_of_v = -1) {
    sizeSubtree[v] = 1;
    bool isCentroid = true;
    for (auto ch : tree[v]) {
        if (ch == parent_of_v) continue;
        SubFindCentroids(ch, v);
        if (sizeSubtree[ch] > N / 2) isCentroid = false;
        sizeSubtree[v] += sizeSubtree[ch];
    }
    if (N - sizeSubtree[v] > N / 2) isCentroid = false;
    if (isCentroid) centroids.push_back(v);
}

void FindCentroids() {
    centroids.clear();
    SubFindCentroids(0, N); //  centoroids 
}
bool dfs(int n,vector<bool> &ok){
    for(int i:tree[n])
        if(ok[i]){
            ok[i]=false;
            if(tree[i].size()==1){
                cout<<n+1<<' '<<i+1<<'\n'<<i+1<<' '<<centroids[1]+1<<'\n';
                return true;
            }
            if(dfs(i,ok))return true;
        }
    return false;
}
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        cin>>N;
        for(int i=0;i<N;i++)tree[i].clear();
        vector<pair<int,int>> A(N-1);
        for(pair<int,int> &p:A){
            cin>>p.first>>p.second;
            p.first--,p.second--;
            tree[p.first].push_back(p.second);
            tree[p.second].push_back(p.first);
        }
        FindCentroids();
        if(centroids.size()==1){
            cout<<A[0].first+1<<' '<<A[0].second+1<<'\n'<<A[0].first+1<<' '<<A[0].second+1<<'\n';
            continue;
        }
        vector<bool> ok(N,true);
        ok[centroids[1]]=false;
        dfs(centroids[0],ok);
    }
}