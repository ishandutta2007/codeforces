#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<int>> A(N);
        vector<int> x(N),y(N);
        for(int i=0;i<N;i++){
            int k;cin>>k;
            for(int j=0;j<k;j++){
                int a;cin>>a;
                A[i].push_back(a-1);
            }
        }
        int cnt=0;
        
        for(int i=0;i<N;i++){
            for(int to:A[i]){
                if(y[to]==0){
                    x[i]=1;
                    y[to]=1;
                    cnt++;
                    break;
                }
            }
        }
        
        if(cnt==N) cout<<"OPTIMAL\n";
        else{
            int a,b;
            for(int i=0;i<N;i++){
                if(x[i]==0){
                    a=i+1;
                    break;
                }
            }
            for(int i=0;i<N;i++){
                if(y[i]==0){
                    b=i+1;
                    break;
                }
            }
            cout<<"IMPROVE\n";
            cout<<a<<" "<<b<<"\n";
        }
    }
}