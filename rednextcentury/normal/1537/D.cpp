#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main(){
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;

        if (n%2!=0) {
            cout<<"Bob"<<endl;
        } else if (n%2==0){

            bool ok =0;
            while(n!=1){
                if (n%2==1) {
                    cout<<"Alice"<<endl;
                    ok=1;
                    break;
                }
                cnt++;
                n/=2;
            }
            if (!ok){
            if (cnt%2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
            }
        }
    }
}