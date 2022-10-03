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
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S,T;cin>>S>>T;
        vector<int> cnt1(26),cnt2(26);
        for(char c:S) cnt1[c-'a']++;
        for(char c:T) cnt2[c-'a']++;
        
        for(int i=0;i<25;i++){
            while(cnt1[i]>cnt2[i]&&cnt1[i]>=K){
                cnt1[i]-=K;
                cnt1[i+1]+=K;
            }
        }
        
        if(cnt1==cnt2) cout<<"Yes\n";
        else cout<<"No\n";
    }
}