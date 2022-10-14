#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n;
    set<int> s1;
    set<int> s2;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        s1.insert(x);
        s2.insert(y);
    }
    int t= min(s1.size(),s2.size());
    cout<<t<<endl;
}