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
const int mod=1000000007,MAX=200005;
const int INF=1<<30;
//const ll INF=1LL<<60;

struct dat{
    ll in;
    ll out;
    ll hp;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<dat> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].in>>S[i].out>>S[i].hp;
        S[i].id=i;
    }
    vector<int> ans;
    
    for(int i=0;i<si(S);i++){
        ans.push_back(S[i].id);
        
        for(int j=i+1;j<si(S);j++){
            S[j].hp-=S[i].in+1-(j-i);
            if(S[i].in+1==(j-i)) break;
        }
        for(int j=i+1;j<si(S);j++){
            if(S[j].hp<0){
                for(int k=j+1;k<si(S);k++){
                    S[k].hp-=S[j].out;
                }
            }
        }
        for(int j=i+1;j<si(S);){
            if(S[j].hp<0){
                S.erase(S.begin()+j);
            }else j++;
        }
    }
    
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}