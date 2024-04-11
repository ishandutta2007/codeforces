#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=500003,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    init(N);
    
    for(int k=0;k<M;k++){
        int a;cin>>a;
        vector<int> A(a);
        for(int i=0;i<a;i++){
            cin>>A[i];
            A[i]--;
            if(i){
                if(!check(A[i-1],A[i])) unite(A[i-1],A[i]);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<size[root(i)];
    }
    
    cout<<endl;
    
}