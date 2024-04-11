#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int par[MAX],size[MAX],maxi[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
        maxi[i]=i;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        maxi[root(a)]=max(maxi[root(a)],maxi[root(b)]);
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
    
    for(int i=0;i<M;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        a--;b--;
        unite(a,b);
    }
    
    ll sum=0;
    
    for(int i=0;i<N;i++){
        if(maxi[root(i)]==i) continue;
        if(maxi[root(i)]-i+1<=size[root(i)]) continue;
        for(int j=i+1;j<N;j++){
            if(check(i,j)) continue;
            unite(i,j);
            sum++;
            
            if(maxi[root(i)]-i+1<=size[root(i)]) break;
            if(maxi[root(i)]<=j) break;
        }
    }
    
    cout<<sum<<endl;
    
    
}