#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    string t="";
    int sum1=0;
    int sum2=0;
    for(char c:s){
        if(c=='('){
            if(sum1==k/2)continue;
            sum1++;
            t+='(';
        }
        else{
            if(sum1==sum2)continue;
            sum2++;
            t+=')';
        }
    }
    cout<<t<<endl;
}