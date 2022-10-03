#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    int maxi=-1;
    for(int i=0;i<N;i++){
        cin>>A[i];
        maxi=max(maxi,A[i]);
    }
    int ans=0,cnt=0;
    for(int i=0;i<N;i++){
        if(A[i]==maxi){
            cnt++;
        }else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    
}