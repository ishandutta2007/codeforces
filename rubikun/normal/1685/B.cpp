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
        int a,b,c,d;cin>>a>>b>>c>>d;
        string S;cin>>S;
        int A=0,B=0;
        for(char c:S){
            if(c=='A') A++;
            else B++;
        }
        if(a+c+d!=A){
            cout<<"NO\n";
            continue;
        }
        string ST;
        int free=0;
        vector<int> X,Y;
        for(char c:S){
            if(ST.empty()||ST.back()!=c) ST+=c;
            else{
                if(si(ST)&1){
                    free+=si(ST)/2;
                }else{
                    if(ST[0]=='A') X.push_back(si(ST)/2);
                    else Y.push_back(si(ST)/2);
                    free+=si(ST)/2-1;
                }
                ST.clear();
                ST+=c;
            }
        }
        
        if(si(ST)){
            if(si(ST)&1){
                free+=si(ST)/2;
            }else{
                if(ST[0]=='A') X.push_back(si(ST)/2);
                else Y.push_back(si(ST)/2);
                free+=si(ST)/2-1;
            }
            ST.clear();
        }
        
        sort(all(X));
        sort(all(Y));
        
        if(c+d<=free){
            cout<<"YES\n";
            continue;
        }
        
        int need=c+d-free;
        
        if(si(X)+si(Y)<need){
            cout<<"NO\n";
            continue;
        }
        
        int can=0,sum=0;
        
        for(int x:X){
            if(sum+x<=c){
                can++;
                sum+=x;
            }
        }
        sum=0;
        for(int x:Y){
            if(sum+x<=d){
                can++;
                sum+=x;
            }
        }
        
        if(can>=need) cout<<"YES\n";
        else cout<<"NO\n";
    }
}