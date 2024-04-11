#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int &i:A)cin>>i;
        sort(A.begin(),A.end());
        cout<<max({A[n-5]*A[n-4]*A[n-3]*A[n-2]*A[n-1],A[0]*A[1]*A[n-3]*A[n-2]*A[n-1],A[0]*A[1]*A[2]*A[3]*A[n-1]})<<endl;
    }
}