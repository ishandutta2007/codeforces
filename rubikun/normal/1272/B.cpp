#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        string T="UDLR";
        vector<int> cnt(4);
        for(int i=0;i<S.size();i++){
            for(int j=0;j<4;j++){
                if(S[i]==T[j]) cnt[j]++;
            }
        }
        
        int a=min(cnt[0],cnt[1]),b=min(cnt[2],cnt[3]);
        
        if(a==0){
            if(b){
                cout<<2<<endl;
                cout<<"LR"<<endl;
            }else cout<<0<<endl;
        }else{
            if(b==0){
                if(a){
                    cout<<2<<endl;
                    cout<<"UD"<<endl;
                }else cout<<0<<endl;
            }else{
                cout<<(a+b)*2<<endl;
                string ans;
                for(int i=0;i<a;i++) ans+='U';
                for(int i=0;i<b;i++) ans+='R';
                for(int i=0;i<a;i++) ans+='D';
                for(int i=0;i<b;i++) ans+='L';
                cout<<ans<<endl;
            }
        }
    }
}