#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a[n+1]=-1;
        a[n+2]=-2;
        a[n+3]=-3;
        int g=0,s=0,b=0;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
        }
        int A=2;
        g=1;
        while(A<=n && a[A]==a[A-1])A++,g++;
        int B=A;
        s=1;B++;
        while((a[B]==a[B-1] || g>=s) && B<=n)B++,s++;
        int last=-1;
        int cur=1;
        for (int C=B+1;C<=n;C++){
            if (a[C]!=a[C-1]){
                if (g<cur && g+s+cur<=n/2)last = cur;
            }
            cur++;
        }
        if (last==-1)cout<<0<<' '<<0<<' '<<0<<endl;
        else cout<<g<<' '<<s<<' '<<last<<endl;
    }
}