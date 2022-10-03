#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        string S;cin>>S;
        if(S!="start"){
            //cout<<endl;
            break;
        }
        
        cout<<"? 0 1"<<endl;
        char c;cin>>c;
        if(c=='x'){
            cout<<"! 1"<<endl;
            continue;
        }
        
        ll left,right;
        ll now=1;
        while(1){
            cout<<"? "<<now<<" "<<now*2<<endl;
            char c;cin>>c;
            if(c=='x'){
                left=now;
                right=now*2;
                break;
            }else{
                now*=2;
            }
        }
        
        while(right-left>1){
            ll mid=(left+right)/2;
            cout<<"? "<<left<<" "<<mid<<endl;
            char c;cin>>c;
            if(c=='x'){
                right=mid;
            }else{
                left=mid;
            }
        }
        
        cout<<"! "<<right<<endl;
    }
}