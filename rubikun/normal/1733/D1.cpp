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
const int mod=998244353,MAX=400005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,X,Y;cin>>N>>X>>Y;
        string A,B;cin>>A>>B;
        vector<int> S;
        for(int i=0;i<N;i++) if(A[i]!=B[i]) S.push_back(i);
        int cn=si(S);
        if(cn&1){
            cout<<-1<<"\n";
            continue;
        }
        if(cn==0){
            cout<<0<<"\n";
        }else if(cn==2){
            if(S[0]+1==S[1]){
                cout<<min(X,2*Y)<<"\n";
            }else{
                cout<<Y<<"\n";
            }
        }else{
            cout<<Y*(cn/2)<<"\n";
        }
    }
}