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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll K;cin>>K;
    string S="codeforces";
    
    if(K==1){
        cout<<S<<endl;
        return 0;
    }
    
    for(int t=1;;t++){
        vector<ll> cnt(10);
        for(int i=0;i<t%10;i++) cnt[i]=t/10+2;
        for(int i=t%10;i<10;i++) cnt[i]=t/10+1;
        
        ll sum=1;
        
        for(int i=0;i<10;i++) sum*=cnt[i];
        
        if(sum>=K){
            for(int i=0;i<10;i++){
                for(int j=0;j<cnt[i];j++){
                    cout<<S[i];
                }
            }
            cout<<endl;
            return 0;
        }
    }
}