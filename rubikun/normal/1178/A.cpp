#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N),ans={1};
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int asum=A[0],bsum=0;
    for(int i=1;i<N;i++){
        if(A[0]>=2*A[i]){
            ans.push_back(i+1);
            asum+=A[i];
        }else{
            bsum+=A[i];
        }
    }
    
    if(asum>bsum){
        cout<<ans.size()<<endl;
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
    }else cout<<0<<endl;
}