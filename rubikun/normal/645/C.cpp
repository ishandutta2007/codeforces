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
    
    int N,K;cin>>N>>K;
    string S;cin>>S;
    vector<int> rui(N+1);
    for(int i=1;i<=N;i++){
        rui[i]=rui[i-1]+1-(int)(S[i-1]-'0');
    }
    
    int left=0,right=N;
    while(right-left>1){
        int mid=(left+right)/2;
        bool f=false;
        for(int i=0;i<N;i++){
            if(S[i]=='1') continue;
            int l=max(0,i-mid),r=min(N-1,i+mid);
            if(rui[r+1]-rui[l]>=K+1) f=true;
        }
        if(f) right=mid;
        else left=mid;
    }
    cout<<right<<endl;
}