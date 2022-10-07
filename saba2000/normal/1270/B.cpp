#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define pb push_back
using namespace std;
int a[200009];
main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int j = 0;
        for(int i = 1; i <= n-1; i++)
            if(abs(a[i] -a[i+1]) >=2) j=i;
        if(j) cout<<"YES"<<endl<<j<<" "<<j+1<<endl;
        else cout<<"NO"<<endl;
    }
}