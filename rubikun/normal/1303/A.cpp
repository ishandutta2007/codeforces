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
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int s=-1,t=-1;
        for(int i=0;i<S.size();i++){
            if(S[i]=='1'&&s==-1){
                s=i;
                t=i;
            }else if(S[i]=='1'){
                t=i;
            }
        }
        
        if(s==-1) cout<<0<<endl;
        else{
            int cnt=0;
            for(int i=s;i<=t;i++){
                if(S[i]=='0') cnt++;
            }
            cout<<cnt<<endl;
        }
    }
}