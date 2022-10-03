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
    string S;cin>>S;
    
    pair<int,string> ans={INF,S};
    
    if(N==12){
        for(int j=1;j<=12;j++){
            for(int k=0;k<60;k++){
                string T;
                
                if(j<10) T+='0';
                T+=to_string(j);
                T+=':';
                if(k<10) T+='0';
                T+=to_string(k);
                
                int cnt=0;
                for(int l=0;l<5;l++){
                    if(S[l]!=T[l]) cnt++;
                }
                
                chmin(ans,mp(cnt,T));
            }
        }
    }else{
        for(int j=0;j<24;j++){
            for(int k=0;k<60;k++){
                string T;
                
                if(j<10) T+='0';
                T+=to_string(j);
                T+=':';
                if(k<10) T+='0';
                T+=to_string(k);
                
                int cnt=0;
                for(int l=0;l<5;l++){
                    if(S[l]!=T[l]) cnt++;
                }
                
                chmin(ans,mp(cnt,T));
            }
        }
    }
    
    cout<<ans.se<<endl;
    
}