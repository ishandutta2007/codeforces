#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
        if(c <= a) cout <<-1;
        else cout <<1;
        cout<<" ";
        if(b * a <= c) cout <<-1;
        else cout<<b;
        cout<<endl;
    }
}