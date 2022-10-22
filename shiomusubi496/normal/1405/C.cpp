#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int N,K;
        string S;
        cin>>N>>K>>S;
        bool ok=false;
        for(int i=0;i<K;i++){
            bool a=false,b=false;
            for(int j=i;j<N;j+=K){
                if(S[j]=='0')a=true;
                else if(S[j]=='1')b=true;
            }
            if(a && b){
                puts("NO");
                ok=true;
                break;
            }else if(a){
                for(int j=i;j<N;j+=K)S[j]='0';
            }else if(b){
                for(int j=i;j<N;j+=K)S[j]='1';
            }
        }
        if(ok)continue;
        int a=0,b=0;
        for(int i=0;i<K;i++){
            if(S[i]=='0')a++;
            else if(S[i]=='1')b++;
        }
        if(a<=K/2 && b<=K/2)puts("YES");
        else puts("NO");
    }
}