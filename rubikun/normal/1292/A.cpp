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
    
    int N,Q;cin>>N>>Q;
    vector<vector<int>> A(2,vector<int>(N+2));
    int cnt=0;
    while(Q--){
        int a,b;cin>>a>>b;
        a--;
        if(A[a][b]==0){
            if(A[(a+1)%2][b-1]) cnt++;
            if(A[(a+1)%2][b]) cnt++;
            if(A[(a+1)%2][b+1]) cnt++;
            
            A[a][b]=1;
            
            if(cnt) cout<<"No"<<"\n";
            else cout<<"Yes"<<"\n";
        }else{
            if(A[(a+1)%2][b-1]) cnt--;
            if(A[(a+1)%2][b]) cnt--;
            if(A[(a+1)%2][b+1]) cnt--;
            
            A[a][b]=0;
            
            if(cnt) cout<<"No"<<"\n";
            else cout<<"Yes"<<"\n";
        }
    }
}