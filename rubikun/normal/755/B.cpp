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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    set<string> A,B;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        A.insert(s);
    }
    int a=0,b=0,c=0;
    for(int i=0;i<M;i++){
        string t;cin>>t;
        if(A.count(t)){
            c++;
            A.erase(t);
        }else{
            b++;
        }
    }
    a=si(A);
    
    for(int q=0;;q++){
        if(q%2==0){
            if(c) c--;
            else if(a) a--;
            else{
                cout<<"NO\n";
                return 0;
            }
        }else{
            if(c) c--;
            else if(b) b--;
            else{
                cout<<"YES\n";
                return 0;
            }
        }
    }
}