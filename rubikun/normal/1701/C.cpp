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
const int mod=1000000007,MAX=400005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<int> cn(N);
        for(int i=0;i<M;i++){
            int x;cin>>x;x--;
            cn[x]++;
        }
        
        int left=0,right=2*M;
        while(right-left>1){
            int mid=(left+right)/2;
            ll rem=M,time=0;
            for(int i=0;i<N;i++){
                int can=min(cn[i],mid);
                rem-=can;
                time+=(mid-can)/2*2;
            }
            if(time>=rem*2) right=mid;
            else left=mid;
        }
        cout<<right<<"\n";
    }
}