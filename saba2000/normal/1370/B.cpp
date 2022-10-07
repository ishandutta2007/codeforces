#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[10009];
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x, y;
        for(int i = 1; i <= 2*n; i++){
            cin>>a[i];
            if(a[i]%2) x.push_back(i);
            else y.push_back(i);}
        for(int i = 1; i <= n-1; i++){
            if(x.size()>=2) {cout<<x.back()<<" "; x.pop_back();cout<<x.back()<<endl,x.pop_back();}
            else {cout<<y.back()<<" "; y.pop_back();cout<<y.back()<<endl,y.pop_back();}
        }

    }


}