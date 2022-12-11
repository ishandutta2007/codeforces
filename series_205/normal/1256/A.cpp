#include <iostream>
#include <algorithm>
using namespace std;
int q;
long long a,b,n,s;
int ans[100000];
int main(){
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>n>>s;
        s=max(s-a*n,s%n);
        if(s<=b)ans[i]=1;
    }
    for(int i=0;i<q;i++){
        cout<<(ans[i]?"YES\n":"NO\n");
    }
    return 0;
}