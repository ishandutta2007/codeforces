#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N,K;cin>>N>>K;
    cout<<"?";
    for(int i=1;i<=K;i++) cout<<" "<<i;
    cout<<endl;
    int a,b;cin>>a>>b;
    
    cout<<"?";
    for(int i=1;i<=K+1;i++){
        if(i!=a) cout<<" "<<i;
    }
    cout<<endl;
    int c,d;cin>>c>>d;
    
    int left=0;
    
    if(b<d){
        for(int j=1;j<=K;j++){
            if(j==a) continue;
            cout<<"?";
            for(int i=1;i<=K+1;i++){
                if(i!=j) cout<<" "<<i;
            }
            cout<<endl;
            int e,f;cin>>e>>f;
            if(a!=e) left++;
        }
    }else{
        for(int j=1;j<=K;j++){
            if(j==a) continue;
            cout<<"?";
            for(int i=1;i<=K+1;i++){
                if(i!=j) cout<<" "<<i;
            }
            cout<<endl;
            int e,f;cin>>e>>f;
            if(a==e) left++;
        }
    }
    
    cout<<"! "<<left+1<<endl;
}