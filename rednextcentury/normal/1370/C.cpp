#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool win[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string B="FastestFinger";
    string A="Ashishgup";
    while(t--){
        int n;
        cin>>n;
        if (n==1) cout<<B<<endl;
        else if (n==2) cout<<A<<endl;
        else {
            if (n%2)cout<<A<<endl;
            else {
                if ((n/2)%2==0) {
                    while(n%2==0)n/=2;
                    if (n==1)cout<<B<<endl;
                    else cout<<A<<endl;
                } else {
                    bool prime=1;
                    n/=2;
                    for (int i=2;i*1LL*i<=n;i++) {
                        if (n%i==0) {
                            prime=0;
                            break;
                        }
                    }
                    if (prime)cout<<B<<endl;
                    else cout<<A<<endl;
                } 
            }
        }
    }
}