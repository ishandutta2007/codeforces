#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int A=-1;
        for (int i=2;i<=2000;i++) {
            if (n%i==0){
                A=i;
                n/=i;
                break;
            }
        }
        if (A==-1){
            cout<<"NO"<<endl;
            continue;
        }
        int B=-1,C=-1;
        for (ll i=2;i*i<n;i++) {
            if (n%i==0 && A!=i){
                B=i, C=n/i;
                break;
            }
        }
        if (B==-1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<A<<' '<<B<<' '<<C<<endl;
    }
}