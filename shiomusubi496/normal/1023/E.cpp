#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n; cin>>n;
    string ans1,ans2;
    for(int x=0,y=0;(n-1-x)+(n-1-y)>n-1 && x<n-1 && y<n-1;){
        cout<<"? "<<x+1<<' '<<y+2<<' '<<n<<' '<<n<<endl;
        string s; cin>>s;
        if(s=="YES")y++,ans1+="R";
        else x++,ans1+="D";
    }
    for(int x=n-1,y=n-1;x+y>n-1 && x>0 && y>0;){
        cout<<"? 1 1 "<<x<<' '<<y+1<<endl;
        string s; cin>>s;
        if(s=="YES")x--,ans2+="D";
        else y--,ans2+="R";
    }
    reverse(ans2.begin(),ans2.end());
    cout<<"! "<<ans1<<ans2<<endl;
}