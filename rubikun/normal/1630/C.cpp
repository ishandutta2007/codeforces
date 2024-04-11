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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),L(N,INF),R(N,-INF);
    for(int i=0;i<N;i++){
        int x;cin>>x;x--;
        A[i]=x;
        chmin(L[x],i);
        chmax(R[x],i);
    }
    
    int ans=0;
    
    int i=0;
    while(i<N){
        int y=A[i];
        if(L[y]==R[y]){
            i++;
            continue;
        }
        int s=L[y],cn=1,las=s+1,to=R[y]-1;
        while(1){
            int ma=to+1;
            for(int j=las;j<=to;j++){
                int x=A[j];
                if(L[x]!=R[x]) chmax(ma,R[x]);
            }
            if(ma==to+1){
                ans+=(to+1-s+1)-(cn+1);
                i=to+2;
                break;
            }else if(ma==N-1){
                cn++;
                ans+=(N-1-s+1)-(cn+1);
                i=N;
                break;
            }else{
                las=to+2;
                to=ma-1;
                cn++;
            }
        }
    }
    
    cout<<ans<<endl;
}