#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef __int64 ll;
char s[1002];
int a[1002];
int main(){
    int n;cin>>n;
    int sum=0;
    if(n==1){
        int t;cin>>t;
        if(t==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        int t;cin>>t;
        sum+=t;
        if(i==n-1){
            if((sum==(n-1))) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}