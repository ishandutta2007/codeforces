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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K,X;cin>>N>>K>>X;
    vector<int> cnt(1024);
    for(int i=0;i<N;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    
    for(int t=0;t<K;t++){
        vector<int> nex(1024);
        int sum=0;
        for(int i=0;i<1024;i++){
            if(cnt[i]==0) continue;
            int x=(sum+cnt[i]+1)/2-(sum+1)/2;
            int y=cnt[i]-x;
            nex[i^X]+=x;
            nex[i]+=y;
            sum+=cnt[i];
        }
        cnt=nex;
    }
    
    for(int i=1023;i>=0;i--){
        if(cnt[i]){
            cout<<i<<" ";
            break;
        }
    }
    for(int i=0;i<1024;i++){
        if(cnt[i]){
            cout<<i<<endl;
            return 0;
        }
    }
}