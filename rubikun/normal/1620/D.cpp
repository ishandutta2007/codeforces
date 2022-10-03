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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        if(A.back()%3==0){
            bool ok=true;
            for(int i=0;i<N;i++) ok&=(A[i]%3==0);
            if(ok) cout<<A.back()/3<<"\n";
            else cout<<A.back()/3+1<<"\n";
        }else if(A.back()%3==1){
            bool ok=true;
            for(int i=0;i<N;i++) ok&=(A[i]%3!=2);
            if(ok) cout<<A.back()/3+1<<"\n";
            else{
                ok=true;
                for(int i=0;i<N;i++){
                    ok&=(A[i]!=1);
                    ok&=(A[i]!=A.back()-1);
                }
                if(ok) cout<<A.back()/3+1<<"\n";
                else cout<<A.back()/3+2<<"\n";
            }
        }else{
            bool ok=true;
            for(int i=0;i<N;i++) ok&=(A[i]%3!=1);
            if(ok) cout<<A.back()/3+1<<"\n";
            else cout<<A.back()/3+2<<"\n";
        }
    }
}