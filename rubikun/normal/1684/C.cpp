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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<vector<int>> A(H,vector<int>(W));
        int L=W,R=-1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin>>A[i][j];
            }
            int l=W,r=-1;
            int mi=INF;
            for(int j=W-1;j>=0;j--){
                if(A[i][j]>mi){
                    l=j;
                }
                chmin(mi,A[i][j]);
            }
            int ma=-INF;
            for(int j=0;j<W;j++){
                if(ma>A[i][j]){
                    r=j;
                }
                chmax(ma,A[i][j]);
            }
            chmin(L,l);
            chmax(R,r);
        }
        if(L==W){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
        bool f=true;
        for(int i=0;i<H;i++){
            swap(A[i][L],A[i][R]);
            for(int j=0;j+1<W;j++){
                f&=(A[i][j]<=A[i][j+1]);
            }
        }
        if(f){
            cout<<L+1<<" "<<R+1<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}