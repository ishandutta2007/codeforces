#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n; cin>>n;
    string s; cin>>s;
    int sum=0;
    bool a=false;
    for(char c:s){
        if(c=='(')sum++;
        else sum--;
        if(sum<0){
            if(a)return puts("No"),0;
            else a=true,sum=0;
        }
    }
    if((sum==0 && !a) || (sum==1 && a))puts("Yes");
    else puts("No");
}