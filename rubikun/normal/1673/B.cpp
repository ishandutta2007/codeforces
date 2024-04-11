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
        string S;cin>>S;
        vector<vector<int>> deta(26);
        int N=si(S);
        for(int i=0;i<N;i++){
            deta[S[i]-'a'].push_back(i);
        }
        
        bool f=true;
        
        for(int i=0;i<26;i++){
            for(int j=0;j+1<si(deta[i]);j++){
                vector<int> cn(26);
                for(int k=deta[i][j]+1;k<deta[i][j+1];k++){
                    cn[S[k]-'a']++;
                }
                for(int k=0;k<26;k++){
                    if(i==k) continue;
                    if(si(deta[k])&&cn[k]==0) f=false;
                }
                if(!f) break;
            }
            if(!f) break;
        }
        
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}