#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,ans=0;cin>>N;
    string S;cin>>S;
    vector<int> X(N),A(N),B(N);
    for(int i=0;i<N;i++){
        X[i]=S[i]-'0';
        if(X[i]==1) ans++;
    }
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    
    for(int i=1;i<=1000;i++){
        int cnt=0;
        for(int j=0;j<N;j++){
            if(i>=B[j]&&(i-B[j])%A[j]==0) X[j]++;
            if(X[j]%2==1) cnt++;
        }
        ans=max(ans,cnt);
    }
    
    cout<<ans<<endl;
    
}