#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    string S;cin>>S;
    vector<int> T(26);
    for(int i=0;i<K;i++){
        char a;cin>>a;
        T[int(a-'a')]++;
    }
    
    ll sum=0;
    
    for(int i=0;i<N;i++){
        int to=i;
        while(to<N&&T[int(S[to]-'a')]) to++;
        
        sum+=ll(to-i)*ll(to-i+1)/2;
        
        if(to!=i) i=to-1;
    }
    
    cout<<sum<<endl;
}