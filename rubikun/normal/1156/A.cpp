#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=0;
    for(int i=1;i<N;i++){
        if(A[i-1]+A[i]==3) ans+=3;
        else if(A[i-1]+A[i]==4) ans+=4;
        else ans=-INF;
    }
    for(int i=2;i<N;i++){
        if(A[i-2]==3&&A[i-1]==1&&A[i]==2) ans--;
    }
    if(ans<0) cout<<"Infinite"<<endl;
    else{
        cout<<"Finite"<<endl;
        cout<<ans<<endl;
    }
}