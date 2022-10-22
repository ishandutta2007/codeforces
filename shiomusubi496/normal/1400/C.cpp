#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;
    cin>>T;
    while(T--){
        int x;
        string S;
        cin>>S>>x;
        int n=S.size();
        vector<bool> A(n);
        for(int i=0;i<n;i++){
            if(i-x<0){
                if(i+x>=n)A[i]=true;
                else if(S[i+x]=='1')A[i]=true;
                else A[i]=false;
            }else if(S[i-x]=='0')A[i]=false;
            else if(i+x>=n)A[i]=true;
            else if(S[i+x]=='0')A[i]=false;
            else A[i]=true;
        }
        string T="";
        for(int i=0;i<n;i++){
            if((i-x>=0 && A[i-x]) || (i+x<n && A[i+x]))T+='1';
            else T+='0';
        }
        if(S==T){
            for(int i=0;i<n;i++)cout<<A[i];
            cout<<endl;
        }else puts("-1");
    }
}