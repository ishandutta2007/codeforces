#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
const int maxn=1000000;
int main()
{
    ll t,s,x;cin>>t>>s>>x;
    x-=t;
    if(x<0){
        cout<<"NO";
        return 0;
    }
    if(((x%s)==0)||(((x%s)==1)&&(x!=1))){
       cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}