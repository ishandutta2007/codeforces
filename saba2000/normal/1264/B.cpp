#include<bits/stdc++.h>
using namespace std;
void P(string s, int k){
    while(k--)
        cout<<s;
}
main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b < a-1 || c < d-1 || a+c < b-1 || b+d < c-1 || abs(a+c-b-d) > 1){
        cout<<"NO"<<endl;
        return 0;
    }
    if(b == a-1){
        if(c || d) {cout<<"NO"<<endl;return 0;}
        cout<<"YES"<<endl;
        P("0 ",1);
        P("1 0 ", b);
        return 0;
    }
    if(c == d-1){
        if(a || b) {cout<<"NO"<<endl;return 0;}
        cout<<"YES"<<endl;
        P("3 ",1);
        P("2 3 ", c);
        return 0;
    }
    cout<<"YES"<<endl;
    int R1 = b -a, R2 = c -d;
    if(R1 > R2) P("1 ",1);
    P("0 1 ",a);
    P("2 1 ", min(R1,R2));
    P("2 3 ",d);
    if(R2 > R1) P("2 ",1);

}
//1010101010123232323232