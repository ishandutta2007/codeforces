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
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N;cin>>N;
    vector<pair<int,int>> X(N);
    vector<int> ans(N);
    
    for(int i=1;i<N;i++){
        cout<<"XOR 1 "<<i+1<<endl;
        cin>>X[i].fi;
        X[i].se=i;
    }
    sort(all(X));
    
    for(int i=0;i+1<N;i++){
        if(X[i].fi==X[i+1].fi){
            cout<<"AND "<<X[i].se+1<<" "<<X[i+1].se+1<<endl;
            int a;cin>>a;
            ans[0]=a^X[i].fi;
            sort(all(X),[](auto a,auto b){
                return a.se<b.se;
            });
            for(int j=1;j<N;j++){
                ans[j]=ans[0]^X[j].fi;
            }
            cout<<"!";
            for(int j=0;j<N;j++) cout<<" "<<ans[j];
            cout<<endl;
            
            return 0;
        }
    }
    
    int A=1,B=N-2;
    int x,y,a,b;
    for(int i=0;i<N;i++){
        if(X[i].fi==B) x=X[i].se;
        if(X[i].fi==A) y=X[i].se;
    }
    
    cout<<"AND "<<1<<" "<<x+1<<endl;
    cin>>a;
    
    cout<<"AND "<<1<<" "<<y+1<<endl;
    cin>>b;
    
    ans[0]+=a&A;
    ans[0]+=b&B;
    
    sort(all(X),[](auto a,auto b){
        return a.se<b.se;
    });
    
    for(int j=1;j<N;j++){
        ans[j]=ans[0]^X[j].fi;
    }
    cout<<"!";
    for(int j=0;j<N;j++) cout<<" "<<ans[j];
    cout<<endl;
    
    return 0;
}