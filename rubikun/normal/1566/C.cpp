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

void solve(){
    int N;cin>>N;
    string S;cin>>S;
    string T;cin>>T;
    //int N=si(S);
    vector<int> A(N);
    for(int i=0;i<N;i++) A[i]=int(S[i]-'0')+int(T[i]-'0');
    int i=0,ans=0;
    while(i<N){
        if(i+1==N){
            if(A[i]==0) ans++;
            if(A[i]==1) ans+=2;
            i++;
        }else if(A[i]==1){
            ans+=2;
            i++;
        }else if(A[i]==0){
            if(A[i+1]==2){
                ans+=2;
                i+=2;
            }else{
                ans++;
                i++;
            }
        }else{
            if(A[i+1]==0){
                ans+=2;
                i+=2;
            }else{
                i++;
            }
        }
    }
    
    cout<<ans<<"\n";
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}