#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s,t;
int x[2000],num=1000,mi=1000;
int ans[3];
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='(')num++;
        else num--;
        x[num]++;
        mi=min(mi,num);
    }
    if(num!=1000){
        cout<<0<<endl<<1<<" "<<1<<endl;
        return 0;
    }
    ans[0]=x[mi];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j])continue;
            t=s;
            t[i]=s[j];
            t[j]=s[i];
            int X[2000]={};
            mi=1000;
            for(int k=0;k<n;k++){
                if(t[k]=='(')num++;
                else num--;
                X[num]++;
                mi=min(mi,num);
            }
            if(ans[0]<X[mi]){
                ans[0]=X[mi];
                ans[1]=i;
                ans[2]=j;
            }
        }
    }
    cout<<ans[0]<<endl<<ans[1]+1<<" "<<ans[2]+1<<endl;
    return 0;
}