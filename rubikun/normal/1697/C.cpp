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
    int N;cin>>N;
    vector<pair<char,int>> S,T;
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(!S.empty()&&S.back().fi==c){
            S.back().se++;
        }else{
            S.push_back(mp(c,1));
        }
    }
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(!T.empty()&&T.back().fi==c){
            T.back().se++;
        }else{
            T.push_back(mp(c,1));
        }
    }
    while(!S.empty()){
        //while(si(S)&&S.back().se==0) S.pop_back();
        //while(si(T)&&T.back().se==0) T.pop_back();
        //if(si(S)==0) break;
        
        if(S.back().fi==T.back().fi){
            S.back().se--;
            if(S.back().se==0) S.pop_back();
            T.back().se--;
            if(T.back().se==0) T.pop_back();
        }else{
            if(T.back().fi=='c'){
                cout<<"NO\n";
                return;
            }else if(T.back().fi=='b'){
                if(si(S)==1){
                    cout<<"NO\n";
                    return;
                }
                if(S[si(S)-2].fi=='b'&&S[si(S)-1].fi=='c'){
                    if(S[si(S)-2].se==1){
                        S.erase(S.begin()+si(S)-2);
                        if(si(S)>=2&&S[si(S)-2].fi==S[si(S)-1].fi){
                            S[si(S)-2].se+=S.back().se;
                            S.pop_back();
                        }
                        T.back().se--;
                        if(T.back().se==0) T.pop_back();
                    }else{
                        S[si(S)-2].se--;
                        T.back().se--;
                        if(T.back().se==0) T.pop_back();
                    }
                }else{
                    cout<<"NO\n";
                    return;
                }
            }else if(T.back().fi=='a'){
                if(si(S)==1){
                    cout<<"NO\n";
                    return;
                }
                if(S[si(S)-2].fi=='a'&&S[si(S)-1].fi=='b'){
                    if(S[si(S)-2].se==1){
                        S.erase(S.begin()+si(S)-2);
                        if(si(S)>=2&&S[si(S)-2].fi==S[si(S)-1].fi){
                            S[si(S)-2].se+=S.back().se;
                            S.pop_back();
                        }
                        T.back().se--;
                        if(T.back().se==0) T.pop_back();
                    }else{
                        S[si(S)-2].se--;
                        T.back().se--;
                        if(T.back().se==0) T.pop_back();
                    }
                }else{
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    
    cout<<"YES\n";
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