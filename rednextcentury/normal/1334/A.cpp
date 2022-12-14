#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ok =1;
        int lastT=0,lastS=0;
        for (int i=1;i<=n;i++){
            int tim,s;
            cin>>tim>>s;
            if (tim<lastT) ok=0;
            if (s<lastS)ok=0;
            if (s-lastS > tim-lastT) ok=0;
            lastT = tim, lastS = s;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}