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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N+1),ans(N+1,-1),rui(N+2);
        ll sum=0;
        for(int i=1;i<=N;i++){
            cin>>A[i];
            sum+=A[i];
            if(A[i]<i) ans[i]=0;
            if(A[i]>N-i+1) ans[i]=1;
        }
        sum/=N;
        
        /*
        for(int i=1;i<=N;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
         */
        
        int remo=sum,remz=N-sum;
        rui[N+1]=INF;
        
        for(int i=N;i>=1;i--){
            rui[i]=remz;
            if(ans[i]==0){
                remz--;
            }else if(ans[i]==1){
                remo--;
            }else{
                auto it=lower_bound(all(rui),i);
                int r=it-rui.begin()-1;
                int x=max(0,r-(i-1));
                if(x==A[i]&&remz){
                    ans[i]=0;
                    remz--;
                }else{
                    ans[i]=1;
                    remo--;
                }
            }
        }
        
        for(int i=1;i<=N;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}