#include <bits/stdc++.h>

using namespace std;



int main(){
    int n,k,last,ck;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>one;
    for(int i=0;i<n;i++){
        if(s[i]=='0') one.push_back(i);
    }
    int l=-1,r=n,m;
    while(r-l>1){
        m=(l+r)/2;
        last=0;
        ck=k-2;
        for(int i=0;i<one.size();i++){
            if(i+1<one.size() && one[i+1]-last-1>m){
                if(one[i+1]-one[i]-1>m) ck=-1;
                last=one[i];
                ck--;
            }
        }
        if(ck>=0) r=m;
        else l=m;
    }
    cout<<r;
}