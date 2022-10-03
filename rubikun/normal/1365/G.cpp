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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> p(13);
    for(int i=0;i<6;i++) p[12-i]=1;
    
    vector<vector<int>> S(N,vector<int>(13)),ans(N,vector<int>(64,1));
    
    int n=0;
    
    set<int> SE;
    
    do{
        
        for(int j=0;j<13;j++){
            S[n][12-j]=p[j];
            if(p[j]) SE.insert(12-j);
        }
        
        n++;
        
        if(n>=N) break;
        
    }while(next_permutation(all(p)));
    
    vector<ll> T;
    
    for(int j=0;j<si(SE);j++){
        int cnt=0;
        for(int i=0;i<N;i++) if(S[i][j]) cnt++;
        cout<<"? "<<cnt<<" ";
        for(int i=0;i<N;i++) if(S[i][j]) cout<<i+1<<" ";
        cout<<endl;
        ll a;cin>>a;
        T.push_back(a);
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0;k<13;k++){
                if(S[i][k]+S[j][k]==1){
                    if(S[i][k]){
                        for(int l=62;l>=0;l--){
                            if(!(T[k]&(1LL<<l))) ans[i][l]=0;
                        }
                    }else{
                        for(int l=62;l>=0;l--){
                            if(!(T[k]&(1LL<<l))) ans[j][l]=0;
                        }
                    }
                }
            }
        }
    }
    
    vector<ll> res(N);
    
    for(int l=0;l<63;l++){
        vector<int> X;
        for(int i=0;i<N;i++){
            if(ans[i][l]) X.push_back(i);
        }
        if(si(X)==1){
            for(int i=0;i<N;i++){
                if(i!=X[0]) res[i]+=(1LL<<l);
            }
        }
        if(si(X)>=2){
            for(int i=0;i<N;i++){
                res[i]+=(1LL<<l);
            }
        }
    }
    cout<<"! ";
    for(int i=0;i<N;i++) cout<<res[i]<<" ";
    cout<<endl;
    
    
}