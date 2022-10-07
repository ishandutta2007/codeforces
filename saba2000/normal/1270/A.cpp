#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define pb push_back
using namespace std;
main(){
    int t;
    cin >>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int A=0,B=0;
        while(a--){int x;
        cin>>x;
        A=max(A,x);}
        while(b--){
            int x;
            cin>>x;
            B= max(B,x);
        }
        if(A >B) cout<<"YES\n";
        else cout<<"NO\n";
    }
}