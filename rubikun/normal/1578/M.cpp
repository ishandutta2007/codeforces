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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<string,int>> S(N);
    for(int i=0;i<N;i++){
        S[i].se=i;
        cin>>S[i].fi;
        for(int j=0;j<si(S[i].fi);j++){
            if(j&1){
                int k=int(S[i].fi[j]-'A');
                k=25-k;
                S[i].fi[j]=char('A'+k);
            }
        }
    }
    
    sort(all(S));
    
    for(int i=0;i<N;i++) cout<<S[i].se+1<<" ";
    cout<<endl;
}