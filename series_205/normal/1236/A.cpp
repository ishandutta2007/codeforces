#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,ans[100];
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        while(b>=1&&c>=2){b--; c-=2; ans[i]++;}
        while(a>=1&&b>=2){a--; b-=2; ans[i]++;}
    }
    for(int i=0;i<t;i++)cout<<ans[i]*3<<endl;
    return 0;
}