#include<bits/stdc++.h>
using namespace std;
main(){
    int s, a,b,c,d;
    cin>>s>>a>>b>>c>>d;
    if(s*a+2*c < s*b + 2*d)
        cout<<"First"<<endl;
    else if(s*a+2*c==s*b+2*d)
        cout<<"Friendship"<<endl;
    else cout<<"Second"<<endl;
}