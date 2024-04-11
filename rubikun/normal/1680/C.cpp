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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=si(S);
        int cnt0=0,cnt1=0;
        vector<int> rui0(N+1),rui1(N+1);
        for(int i=0;i<N;i++){
            rui0[i+1]=rui0[i]+(S[i]=='0');
            rui1[i+1]=rui1[i]+(S[i]=='1');
        }
        cnt0=rui0.back();
        cnt1=rui1.back();
        
        int left=-1,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            bool ok=false;
            for(int i=0;i<=N;i++){
                auto it=upper_bound(all(rui0),rui0[i]+mid);
                if(it==rui0.end()){
                    if(rui1[i]<=mid) ok=true;
                }else{
                    if(cnt1-(rui1[it-rui0.begin()-1]-rui1[i])<=mid) ok=true;
                }
            }
            if(ok) right=mid;
            else left=mid;
        }
        
        cout<<right<<"\n";
    }
}