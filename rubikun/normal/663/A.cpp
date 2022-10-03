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
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<char> S;
    int a=1,b=0;
    while(1){
        char c;cin>>c;
        if(c=='?') continue;
        if(c=='=') break;
        
        if(c=='+') a++;
        if(c=='-') b++;
        
        S.push_back(c);
    }
    int N,sum=0;cin>>N;
    
    vector<int> ans(si(S)+1);
    ans[0]=N;
    sum=N;
    for(int i=1;i<=si(S);i++){
        if(S[i-1]=='+'){
            ans[i]=N;
            sum+=N;
        }
        else{
            ans[i]=1;
            sum--;
        }
    }
    
    if(sum<N){
        cout<<"Impossible\n";
        return 0;
    }
    
    for(int i=0;i<=si(S);i++){
        if(sum==N) break;
        if(sum>N){
            if(i==0||S[i-1]=='+'){
                int x=sum-N,y=ans[i]-1;
                ans[i]-=min(x,y);
                sum-=min(x,y);
            }else{
                int x=sum-N,y=N-ans[i];
                ans[i]+=min(x,y);
                sum-=min(x,y);
            }
        }
    }
    
    if(sum!=N){
        cout<<"Impossible\n";
        return 0;
    }else{
        cout<<"Possible\n";
        cout<<ans[0];
        
        for(int i=1;i<=si(S);i++){
            cout<<" ";
            cout<<S[i-1];
            cout<<" ";
            cout<<ans[i];
        }
        cout<<" = "<<N<<endl;
    }
}