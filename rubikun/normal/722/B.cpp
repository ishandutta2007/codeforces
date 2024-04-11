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
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    string T="aiueoy";
    
    bool ok=true;
    string SS;getline(cin,SS);
    for(int i=0;i<N;i++){
        string S;
        getline(cin,S);
        int cnt=0;
        
        for(int j=0;j<si(S);j++){
            for(int k=0;k<6;k++){
                if(S[j]==T[k]) cnt++;
            }
        }
        
        if(cnt!=A[i]) ok=false;
        
        //cout<<S<<endl;
    }
    
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}