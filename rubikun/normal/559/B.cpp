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
    
    string S,T;cin>>S>>T;
    int N=si(S);
    int mi=N;
    while(mi%2==0) mi/=2;
    for(int i=N;;i/=2){
        vector<string> A,B;
        for(int s=0;s<N;s+=i){
            vector<string> UU;
            for(int t=s;t<s+i;t+=mi){
                UU.push_back(S.substr(t,mi));
            }
            sort(all(UU));
            A.push_back("");
            for(auto a:UU) A.back()+=a;
            
            vector<string> VV;
            for(int t=s;t<s+i;t+=mi){
                VV.push_back(T.substr(t,mi));
            }
            sort(all(VV));
            B.push_back("");
            for(auto a:VV) B.back()+=a;
        }
        sort(all(A));
        sort(all(B));
        if(A!=B){
            cout<<"NO\n";
            return 0;
        }
        
        if(i&1){
            cout<<"YES\n";
            return 0;
        }
    }
}