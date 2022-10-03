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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        string S;cin>>S;
        int N=H*W;
        vector<int> ans(N),ans2(N);
        for(int j=0;j<W;j++){
            int now=j;
            for(int i=0;i<H;i++){
                if(S[now]=='1'){
                    ans[now]++;
                    break;
                }
                now+=W;
            }
        }
        
        for(int i=1;i<N;i++) ans[i]+=ans[i-1];
        //for(int i=0;i<N;i++) ans[i]=W-ans[i];
        
        vector<int> rui(N);
        if(S[0]=='1') rui[0]=1;
        for(int i=1;i<N;i++){
            rui[i]=rui[i-1];
            if(S[i]=='1') rui[i]++;
        }
        
        auto f=[&](int l,int r){
            int res=0;
            res+=rui[r];
            if(l>0) res-=rui[l-1];
            return res;
        };
        
        for(int i=0;i<N;i++){
            if(f(i-W+1,i)){
                ans2[i]++;
            }
        }
        
        for(int i=W;i<N;i++) ans2[i]+=ans2[i-W];
        
        for(int i=0;i<N;i++) cout<<ans[i]+ans2[i]<<" ";
        cout<<"\n";
    }
}