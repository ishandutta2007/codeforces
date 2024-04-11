#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<20,INF=1<<30;

int bit[MAX+1],n;

//1-indexed

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A(M+1),when(N+1),mini(N+1),maxi(N+1);
    for(int i=0;i<M;i++) cin>>A[i+1];
    n=N+M+3;
    for(int i=1;i<=N;i++){
        add(i,1);
        when[i]=N+1-i;
        mini[i]=i;
        maxi[i]=i;
    }
    
    for(int i=1;i<=M;i++){
        int s=sum(N+M)-sum(when[A[i]]-1);
        maxi[A[i]]=max(maxi[A[i]],s);
        mini[A[i]]=1;
        
        add(when[A[i]],-1);
        add(N+i,1);
        when[A[i]]=N+i;
    }
    
    for(int i=1;i<=N;i++){
        int s=sum(N+M)-sum(when[i]-1);
        maxi[i]=max(maxi[i],s);
        
        cout<<mini[i]<<" "<<maxi[i]<<"\n";
    }
}