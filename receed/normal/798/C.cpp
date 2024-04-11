#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int n, g=0, ans=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        g=gcd(g, a[i]);
    }
    if(g==1){
        for(int i=0;i<n-1;i++)
            if(a[i]%2!=0){
                ans++;
                if(a[i+1]%2!=0) a[i+1]++;
                else ans++;
            }
        if(a[n-1]%2!=0)
            ans+=2;
    }
    cout<<"YES\n"<<ans;
    return 0;
}