#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll k,n,a[10]={1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};

int main(){
    cin>>k;
    while(k--){
        cin>>n;
        int ans=0;
        for(int i=0;i<10;i++){
            for(int j=1;j<=9;j++){
                if(a[i]*j<=n){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}