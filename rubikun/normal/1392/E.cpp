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
const int mod=1000000007,MAX=200005,INF=1<<30;

ll A[35][35],B[35][35];
ll rui[65];

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    rui[1]=1;
    for(int i=2;i<=62;i++) rui[i]=rui[i-1]*2;
    
    for(int i=0;i<30;i+=2){
        for(int j=0;j<30;j++){
            B[i][j]=i+j;
            A[i][j]=rui[i+j];
        }
    }
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int Q;cin>>Q;
    
    while(Q--){
        ll k;cin>>k;
        int nowi=0,nowj=0;
        vector<pair<int,int>> ans;
        
        while(nowi!=N&&nowj!=N){
            ans.push_back(mp(nowi,nowj));
            if(nowi<N-1){
                if(B[nowi+1][nowj]){
                    if(k&(1LL<<(B[nowi+1][nowj]-1))){
                        k-=1LL<<(B[nowi+1][nowj]-1);
                        nowi++;
                    }else{
                        nowj++;
                    }
                }else{
                    if(k&(1LL<<(B[nowi][nowj+1]-1))){
                        k-=1LL<<(B[nowi][nowj+1]-1);
                        nowj++;
                    }else{
                        nowi++;
                    }
                }
            }else nowj++;
        }
        
        for(auto a:ans) cout<<a.fi+1<<" "<<a.se+1<<endl;
    }
}