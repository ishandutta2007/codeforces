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
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin>>A[i][j];
            }
        }
        vector<vector<int>> L(H,vector<int>(W,INF)),R(H,vector<int>(W,-INF));
        L[0][0]=R[0][0]=A[0][0];
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(j+1<W){
                    chmin(L[i][j+1],L[i][j]+A[i][j+1]);
                    chmax(R[i][j+1],R[i][j]+A[i][j+1]);
                }
                if(i+1<H){
                    chmin(L[i+1][j],L[i][j]+A[i+1][j]);
                    chmax(R[i+1][j],R[i][j]+A[i+1][j]);
                }
            }
        }
        
        if((H+W-1)&1){
            cout<<"NO\n";
        }else{
            if(L[H-1][W-1]<=0&&0<=R[H-1][W-1]){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}