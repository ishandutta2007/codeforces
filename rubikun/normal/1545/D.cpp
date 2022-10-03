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
const int mod=998244353,MAX=200005,INF=1<<28;

int main(){
    
    int M,K;cin>>M>>K;
    vector<vector<ll>> A(K,vector<ll>(M));
    vector<ll> sum(K),diff(K-1),dsum(K);
    for(int i=0;i<K;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            sum[i]+=A[i][j];
            dsum[i]+=A[i][j]*A[i][j];
        }
        if(i) diff[i-1]=sum[i]-sum[i-1];
    }
    
    map<ll,ll> MA;
    for(int i=0;i<K-1;i++) MA[diff[i]]++;
    ll cor=-1;
    for(auto x:MA) if(x.se>=3) cor=x.fi;
    
    for(int i=0;i<K-1;i++){
        if(diff[i]!=cor){
            ll tasu=cor-diff[i],vsum;
            if(i>=2) vsum=dsum[0]+dsum[2]-dsum[1]-dsum[1];
            else vsum=dsum[K-3]+dsum[K-1]-dsum[K-2]-dsum[K-2];
            
            for(int j=0;j<M;j++){
                A[i+1][j]+=tasu;
                ll sumsum=0;
                for(int jj=0;jj<M;jj++){
                    sumsum+=A[i+1][jj]*A[i+1][jj];
                }
                if(dsum[i]+dsum[i+2]-sumsum-sumsum==vsum){
                    cout<<i+1<<" "<<A[i+1][j]<<endl;
                    return 0;
                }
                A[i+1][j]-=tasu;
            }
        }
    }
}