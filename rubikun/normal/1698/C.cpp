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
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        if(N==3){
            ll x=A[0]+A[1]+A[2];
            bool f=false;
            f|=(A[0]==x);
            f|=(A[1]==x);
            f|=(A[2]==x);
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            vector<ll> X,Y;
            for(int i=0;i<N;i++){
                if(A[i]<0) X.push_back(A[i]);
                if(A[i]>0) Y.push_back(A[i]);
            }
            if(si(X)>2||si(Y)>2){
                cout<<"NO\n";
            }else{
                vector<ll> Z;
                for(ll a:X) Z.push_back(a);
                for(ll a:Y) Z.push_back(a);
                for(int t=0;t<min(3,N-si(X)-si(Y));t++) Z.push_back(0);
                bool f=true;
                for(int i=0;i<si(Z);i++){
                    for(int j=i+1;j<si(Z);j++){
                        for(int k=j+1;k<si(Z);k++){
                            f&=(binary_search(all(A),Z[i]+Z[j]+Z[k]));
                        }
                    }
                }
                if(f) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
    
}