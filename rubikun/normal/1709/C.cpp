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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int cnl=0,cnr=0;
        vector<int> rem;
        for(int i=0;i<si(S);i++){
            if(S[i]=='('){
                cnl++;
            }else if(S[i]==')'){
                cnr++;
            }else{
                rem.push_back(i);
            }
        }
        
        int a=si(S)/2-cnl,b=si(S)/2-cnr;
        
        if(a==0||b==0){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<si(rem);i++){
            if(i<a-1){
                S[rem[i]]='(';
            }else if(i==a-1){
                S[rem[i]]=')';
            }else if(i==a){
                S[rem[i]]='(';
            }else{
                S[rem[i]]=')';
            }
        }
        int sum=0;
        bool f=true;
        for(char c:S){
            if(c=='(') sum++;
            else sum--;
            if(sum<0) f=false;
        }
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
    }
}