#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cout<<"a"<<endl;
    int x;cin>>x;
    if(x==0) return 0;
    
    if(x==300){
        for(int i=0;i<x;i++){
            cout<<'b';
        }
        cout<<endl;
        return 0;
    }
    
    for(int i=0;i<x+1;i++){
        cout<<'a';
    }
    cout<<endl;
    int y;cin>>y;
    if(y==x+1){
        for(int i=0;i<x;i++){
            cout<<'b';
        }
        cout<<endl;
        return 0;
    }
    
    //length==x+1,b==y
    
    if(y==0){
        for(int i=0;i<x+1;i++){
            cout<<'a';
        }
        cout<<endl;
        return 0;
    }
    
    string ans;
    
    int acnt=x+1-y,bcnt=y;
    
    for(int i=0;i<x;i++){
        for(int j=0;j<x+1;j++){
            if(i==j) cout<<'b';
            else cout<<'a';
        }
        cout<<endl;
        
        int z;cin>>z;
        
        if(z==y-1){
            ans+='b';
            bcnt--;
        }
        else{
            ans+='a';
            acnt--;
        }
    }
    
    if(acnt) ans+='a';
    else ans+='b';
    
    cout<<ans<<endl;
    
    return 0;
    
}