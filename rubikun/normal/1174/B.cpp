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
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    int cnt=0;
    for(int i=0;i<N;i++){
        if(A[i]&1) cnt++;
    }
    if(cnt==0||cnt==N){
        for(int i=0;i<N;i++) cout<<A[i]<<" ";
        cout<<endl;
    }else{
        sort(all(A));
        for(int i=0;i<N;i++) cout<<A[i]<<" ";
        cout<<endl;
    }
}