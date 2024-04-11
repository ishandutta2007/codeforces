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
    
    int N;cin>>N;
    string S;cin>>S;
    if(N<=10){
        int ans=-1;
        for(int a=0;a<N;a++){
            for(int b=a;b<N;b++){
                for(int c=0;c<N;c++){
                    for(int d=c;d<N;d++){
                        string A=S.substr(a,b-a+1);
                        string B=S.substr(c,d-c+1);
                        int X=0,Y=0;
                        for(char c:A){
                            X*=2;
                            X+=(int)(c-'0');
                        }
                        for(char c:B){
                            Y*=2;
                            Y+=(int)(c-'0');
                        }
                        chmax(ans,X|Y);
                    }
                }
            }
        }
        if(ans==0){
            cout<<0<<endl;
            return 0;
        }
        string re;
        while(ans){
            re+=char('0'+ans%2);
            ans/=2;
        }
        reverse(all(re));
        cout<<re<<"\n";
        return 0;
    }
    
    string ans="0";
    
    string A;
    for(int i=0;i<si(S);i++){
        if(S[i]=='1'){
            A=S.substr(i);
            break;
        }
    }
    S=A;
    
    for(int l=0;l<30;l++){
        for(int r=si(S)-30;r<si(S);r++){
            if(r-l+1<si(S)-30) continue;
            if(S[l]=='0') continue;
            string B=S.substr(l,r-l+1);
            string C=A;
            for(int i=0;i<si(B);i++){
                if(B[i]=='1'){
                    C[si(A)-si(B)+i]='1';
                }
            }
            if(si(ans)<si(C)) ans=C;
            else if(si(ans)==si(C)) chmax(ans,C);
        }
    }
    
    cout<<ans<<endl;
}