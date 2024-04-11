#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long p[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)cin>>p[i];
        long long x,a,y,b;
        cin>>x>>a>>y>>b;
        if (x<y)swap(x,y),swap(a,b);
        long long k;
        cin>>k;
        sort(p+1,p+n+1);
        int l=1,r=n;
        int ret=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int A=0,B=0,both=0;
            for (int i=1;i<=mid;i++){
                if (i%a==0 && i%b==0)both++;
                else if (i%a==0)A++;
                else if (i%b==0)B++;
            }
            long long cur=0;
            for (int i=1;i<=mid;i++){
                long long X=0;
                if (both) {
                    X = p[n-i+1]*(x+y) / 100;
                    both--;
                } else if (A) {
                    X = p[n-i+1]*x/100;
                    A--;
                } else if (B){
                    X = p[n-i+1]*y/100;
                    B--;
                }
                cur+=X;
            }
            if (cur>=k)ret=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<ret<<'\n';
    }
}