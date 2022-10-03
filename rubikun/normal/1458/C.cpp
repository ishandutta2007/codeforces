#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=105,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<vector<int>> A(N,vector<int>(N)),B;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>A[i][j];
                A[i][j]--;
            }
        }
        string S;cin>>S;
        
        vector<int> p(3),v={0,1,2};
        
        for(char c:S){
            if(c=='R') p[1]++;
            if(c=='L') p[1]--;
            if(c=='D') p[0]++;
            if(c=='U') p[0]--;
            if(c=='I'){
                swap(p[1],p[2]);
                swap(v[1],v[2]);
            }
            if(c=='C'){
                swap(p[0],p[2]);
                swap(v[0],v[2]);
            }
        }
        
        B=A;
        
        for(int k=0;k<3;k++){
            p[k]=(p[k]%N+N)%N;
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                vector<int> to(3);
                for(int k=0;k<3;k++){
                    to[k]=p[k];
                    if(v[k]==0){
                        to[k]=(to[k]+i)%N;
                    }
                    if(v[k]==1){
                        to[k]=(to[k]+j)%N;
                    }
                    if(v[k]==2){
                        to[k]=(to[k]+A[i][j])%N;
                    }
                }
                
                B[to[0]][to[1]]=to[2];
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<B[i][j]+1<<" ";
            }
            cout<<endl;
        }
    }
}