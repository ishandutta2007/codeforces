#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int B,K;cin>>B>>K;
    if(B%2==0){
        for(int i=0;i<K;i++){
            int a;cin>>a;
            if(i==K-1){
                if(a%2==0) cout<<"even"<<endl;
                else cout<<"odd"<<endl;
            }
        }
    }else{
        int cnt=0;
        for(int i=0;i<K;i++){
            int a;cin>>a;
            cnt+=a%2;
        }
        if(cnt%2==0) cout<<"even"<<endl;
        else cout<<"odd"<<endl;
    }
}