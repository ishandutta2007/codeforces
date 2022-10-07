#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> a){
    if(a.size() == 0) return 1;
    int m = 0, I = 0;
    for (int i = 1; i < a.size(); i++){
        if(abs(a[i] - a[i-1]) >= 2) return 0;
        if(a[i] > a[I]) I =i;
    }
    vector<int> b;
    for (int i = 0; i < a.size(); i++){
        if(i!=I) b.push_back(a[i]);
    }
    return solve(b);
}
main(){
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0 ;i < n; i++){
       int x;
       cin >>x;
       a.push_back(x);
    }
    if(solve(a)) cout <<"YES"<<endl; else cout<<"NO"<<endl;
}