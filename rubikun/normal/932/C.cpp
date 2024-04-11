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
    
    int N,A,B;cin>>N>>A>>B;
    for(int i=0;i*A<=N;i++){
        int j=(N-i*A)/B;
        if(i*A+j*B!=N) continue;
        
        int now=1;
        vector<int> ans;
        
        for(int k=0;k<i;k++){
            for(int x=1;x<A;x++) ans.push_back(now+x);
            ans.push_back(now);
            now+=A;
        }
        
        for(int k=0;k<j;k++){
            for(int x=1;x<B;x++) ans.push_back(now+x);
            ans.push_back(now);
            now+=B;
        }
        
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
        return 0;
    }
    
    cout<<-1<<endl;
}