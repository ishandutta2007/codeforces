#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1000003,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N),B(N),diffA,diffB;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(i) diffA.push_back(A[i]-A[i-1]);
    }
    
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
        if(i) diffB.push_back(B[i]-B[i-1]);
    }
    
    sort(all(diffA));
    sort(all(diffB));
    
    bool ok=true;
    
    for(int i=0;i<N-1;i++){
        if(diffA[i]!=diffB[i]) ok=false;
    }
    
    if(A[0]!=B[0]) ok=false;
    if(A[N-1]!=B[N-1]) ok=false;
    
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}