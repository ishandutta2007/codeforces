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

void solve(){
    string S,T;cin>>S>>T;
    vector<int> cnt(26);
    for(int i=0;i<si(S);i++){
        cnt[S[i]-'A']++;
    }
    for(int i=0;i<si(T);i++){
        cnt[T[i]-'A']--;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]<0){
            cout<<"NO\n";
            return;
        }
        for(int t=0;t<cnt[i];t++){
            for(int j=0;j<si(S);j++){
                if(S[j]==char('A'+i)){
                    S.erase(S.begin()+j);
                    break;
                }
            }
        }
    }
    if(S==T){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}