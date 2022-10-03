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
        ll N,K,X;cin>>N>>K>>X;
        vector<ll> RL;
        string S;cin>>S;
        for(int i=0;i<N;i++){
            if(S[i]=='a'){
                RL.push_back(-1);
            }else{
                if(si(RL)&&RL.back()>=0) RL.back()+=K;
                else RL.push_back(K);
            }
        }
        
        //for(ll a:RL) cout<<a<<" ";
        //cout<<endl;
        
        for(int i=0;i<si(RL);i++){
            if(RL[i]==-1){
                cout<<'a';
            }else{
                ll pat=1;
                for(int j=i+1;j<si(RL);j++){
                    if(RL[j]>=0){
                        if(pat>INF/(RL[j]+1)){
                            pat=INF;
                        }else{
                            pat*=(RL[j]+1);
                        }
                    }
                }
                //cout<<X<<" "<<pat<<endl;
                X-=pat;
                while(1){
                    if(X<=0){
                        X+=pat;
                        break;
                    }
                    cout<<'b';
                    X-=pat;
                }
            }
        }
        cout<<"\n";
    }
}