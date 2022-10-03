#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=S.size();
    vector<int> A,B,C;
    for(int i=0;i<N;i++){
        if(S[i]=='(') A.push_back(i);
    }
    for(int i=N-1;i>=0;i--){
        if(S[i]==')') B.push_back(i);
    }
    
    for(int i=0;i<min(A.size(),B.size());i++){
        if(A[i]<B[i]){
            C.push_back(A[i]);
            C.push_back(B[i]);
        }
    }
    sort(all(C));
    if(C.size()==0){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    cout<<C.size()<<endl;
    
    for(int i=0;i<C.size();i++){
        cout<<C[i]+1<<" ";
    }
    cout<<endl;
}