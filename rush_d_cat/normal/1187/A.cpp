#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200000 + 10;
int T;
int n,s,t;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        int x=s+t-n;
        int ans=max(s-x,t-x)+1;
        cout<<ans<<endl;
    }
}