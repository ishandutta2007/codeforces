#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> S,ma,cma;
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        S.push_back(a);
    }
    ma.push_back(1);
    cma.push_back(1);
    for(int i=1;i<n;i++){
        cma.push_back(S[i-1]<S[i] ? cma[cma.size()-1]+1:1);
        ma.push_back(ma[ma.size()-1]>cma[cma.size()-1] ? ma[ma.size()-1]:cma[cma.size()-1]);
    }
    cout<<ma[ma.size()-1];
    return 0;
}