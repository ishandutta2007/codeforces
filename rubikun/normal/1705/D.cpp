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
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N;cin>>N;
        string S,T;cin>>S>>T;
        vector<pair<int,int>> A,B;
        for(int q=0;q<2;q++){
            int i=0;
            while(i<N){
                if(S[i]=='0'){
                    i++;
                    continue;
                }
                int j=i;
                while(j<N&&S[j]=='1') j++;
                A.push_back(mp(i,j-1));
                i=j;
            }
            swap(S,T);
            swap(A,B);
        }
        if(si(A)!=si(B)){
            cout<<-1<<"\n";
            continue;
        }
        if(S[0]!=T[0]||S.back()!=T.back()){
            cout<<-1<<"\n";
            continue;
        }
        if(S==T){
            cout<<0<<"\n";
            continue;
        }
        
        ll ans=0;
        
        for(int t=0;t<si(A);t++){
            int a=A[t].fi,b=A[t].se,c=B[t].fi,d=B[t].se;
            
            ans+=abs(d-b);
            ans+=abs(c-a);
        }
        
        cout<<ans<<"\n";
    }
}