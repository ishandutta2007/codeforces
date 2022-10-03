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

map<string,bool> dp[2];

bool solve(string S,int t){
    if(dp[t].count(S)) return dp[t][S];
    bool win=false;
    
    for(int i=0;i<si(S);i++){
        if(S[i]==char('0'+t)){
            if(i){
                string T=S;
                T[i-1]='2';
                T[i]='2';
                win|=(!solve(T,t^1));
            }
            if(i+1<si(S)){
                string T=S;
                T[i+1]='2';
                T[i]='2';
                win|=(!solve(T,t^1));
            }
        }
    }
    
    return dp[t][S]=win;
}

int grundy[1005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    grundy[0]=0;
    for(int t=1;t<=1000;t++){
        set<int> SE;
        for(int i=0;i<t;i++){
            int l=max(0,i-1),r=max(0,t-i-2);
            SE.insert(grundy[l]^grundy[r]);
        }
        for(int i=0;;i++){
            if(!SE.count(i)){
                grundy[t]=i;
                break;
            }
        }
    }
    
    /*
    for(int i=0;i<34;i++){
        for(int j=i;j<1000;j+=34){
            cout<<grundy[j]<<" ";
        }
        cout<<endl;
    }
    */
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        if(N&1){
            int cn=0;
            for(char c:S){
                if(c=='R') cn++;
            }
            if(cn>N-cn){
                cout<<"Alice\n";
            }else{
                cout<<"Bob\n";
            }
        }else{
            int cn=0;
            for(char c:S){
                if(c=='R') cn++;
            }
            if(cn>N-cn){
                cout<<"Alice\n";
            }else if(cn<N-cn){
                cout<<"Bob\n";
            }else{
                int X=0;
                int i=0;
                while(i<N-1){
                    int j=i+1;
                    if(S[i]!=S[j]){
                        while(j<N&&S[j-1]!=S[j]) j++;
                        if(j-i-1<=340){
                            X^=grundy[j-i-1];
                        }else{
                            int p=(j-i-1-340)%34;
                            X^=grundy[p+340];
                        }
                        i=j;
                    }else{
                        i++;
                    }
                }
                
                if(X){
                    cout<<"Alice\n";
                }else{
                    cout<<"Bob\n";
                }
            }
        }
    }
}