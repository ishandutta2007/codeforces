#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A=0,B=0;
        int m = n;
        while(m--){
            int a;
            scanf("%d", &a);
            if(a&1) A++; else B++;
        }
        if(n % 2 == 0 && A < n && A>0 ) cout<<"YES"<<endl;
        else if(n % 2 == 1 && A>0 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}