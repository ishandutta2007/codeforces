#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int a,b,c;cin>>a>>b>>c;
        if(a+c<=b) cout<<0<<endl;
        else if(a>b+c) cout<<c+1<<endl;
        else{
            int left=0,right=c;
            while(right-left>1){
                int mid=(left+right)/2;
                if(a+mid>b+(c-mid)) right=mid;
                else left=mid;
            }
            cout<<c-right+1<<endl;
        }
    }
}