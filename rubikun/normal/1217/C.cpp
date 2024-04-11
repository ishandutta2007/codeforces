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
        string S;cin>>S;
        int N=S.size(),ans=0;
        
        int last1=-1;
        for(int i=0;i<N;i++){
            if(S[i]=='0') continue;
            ans++;
            int sum=1;
            for(int r=1;r<18;r++){
                sum*=2;
                if(i+r>=N) break;
                if(S[i+r]=='1') sum++;
                if(r+1==sum) ans++;
                else if(i-last1+r>=sum) ans++;
            }
            last1=i;
        }
        
        cout<<ans<<endl;
        
    }
}