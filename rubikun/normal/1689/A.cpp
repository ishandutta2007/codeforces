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
        int N,M,K;cin>>N>>M>>K;
        string S,T;cin>>S>>T;
        sort(all(S));reverse(all(S));
        sort(all(T));reverse(all(T));
        string res;
        int x=0;
        while(si(S)&&si(T)){
            if(S.back()<T.back()){
                if(x>0&&x==K){
                    res+=T.back();T.pop_back();
                    x=-1;
                }else{
                    res+=S.back();S.pop_back();
                    if(x<=0) x=1;
                    else x++;
                    //x++;
                }
            }else{
                if(x<0&&x==-K){
                    res+=S.back();S.pop_back();
                    x=1;
                }else{
                    res+=T.back();T.pop_back();
                    if(x>=0) x=-1;
                    else x--;
                    //x--;
                }
            }
        }
        
        cout<<res<<"\n";
    }
}