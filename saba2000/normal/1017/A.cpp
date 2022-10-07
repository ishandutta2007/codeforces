#include<bits/stdc++.h>
#define Fi first
#define Se second
using namespace std;
main(){
    int n;
    cin >> n;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int s = a+b+c+d;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a+b+c+d > s) ans++;
    }
    cout<<ans+1<<endl;
}