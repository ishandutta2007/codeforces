#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        int ma=0;
        for(int i=0;i<31;i++){
            if(N&(1<<i)) ma=i;
        }
        cout<<ma<<endl;
        
        int now=0,sum=ma+1;
        vector<int> ans;
        for(int t=0;t<ma;t++){
            if(sum==N){
                ans.push_back(0);
                continue;
            }
            int use=min(now+1,(N-sum)/(ma-t));
            ans.push_back(use);
            now+=use;
            sum+=use*(ma-t);
        }
        
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}