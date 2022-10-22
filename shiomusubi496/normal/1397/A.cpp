#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int a[26]{};
        for(int i=0;i<N;i++){
            string S;
            cin>>S;
            for(char &c:S)a[c-'a']++;
        }
        bool b=true;
        for(int i=0;i<26;i++){
            if(a[i]%N)b=false;
        }
        cout<<(b?"YES":"NO")<<endl;
    }
}