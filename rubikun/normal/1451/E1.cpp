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
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    int N;cin>>N;
    int a,b,c,d,e;
    
    cout<<"XOR 1 2"<<endl;
    cin>>a;
    
    cout<<"XOR 1 3"<<endl;
    cin>>b;
    
    cout<<"AND 1 2"<<endl;
    cin>>c;
    
    cout<<"AND 1 3"<<endl;
    cin>>d;
    
    cout<<"AND 2 3"<<endl;
    cin>>e;
    
    int x=0;
    for(int k=0;k<16;k++){
        if((a&(1<<k))==0){
            if(c&(1<<k)) x+=1<<k;
        }else{
            if((b&(1<<k))==0){
                if(d&(1<<k)) x+=1<<k;
            }else{
                if((e&(1<<k))==0) x+=1<<k;
            }
        }
    }
    
    vector<int> ans(N);
    ans[0]=x;
    ans[1]=x^a;
    ans[2]=x^b;
    
    for(int i=3;i<N;i++){
        cout<<"XOR 1 "<<i+1<<endl;
        cin>>ans[i];
        ans[i]^=x;
    }
    
    cout<<"!";
    for(int i=0;i<N;i++) cout<<" "<<ans[i];
    cout<<endl;
}