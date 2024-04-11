#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    bool ok=false;
    int l=-1,r=-1;
    for(int i=0;i<S.size();i++){
        if(S[i]=='[') ok=true;
        if(ok){
            if(S[i]==':'){
                l=i;
                break;
            }
        }
    }
    ok=false;
    for(int i=S.size()-1;i>=0;i--){
        if(S[i]==']') ok=true;
        if(ok){
            if(S[i]==':'){
                r=i;
                break;
            }
        }
    }
    if(l>=0&&r>=0&&l<r){
        int cnt=0;
        for(int i=l+1;i<r;i++){
            if(S[i]=='|') cnt++;
        }
        cout<<cnt+4<<endl;
    }else cout<<-1<<endl;
    
    
}