#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
int t,s,a,b,c;
int main(){
    cin>>t;
    while(t--){
    	cin>>s>>a>>b>>c;
        LL ans=s/c;
        s=s%c;
        ans+=(ans/a)*b;
        cout<<ans<<endl;
    }
    return 0;
}