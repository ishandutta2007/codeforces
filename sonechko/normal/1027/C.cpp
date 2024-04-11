#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        int last=0;
        long double ans=2e18;
        int a1=0,a2=0;
        for (int i=1; i<n; i++)
        {
            if (a[i]==a[i+1]&&last!=0)
            {
                int p=2*(a[i]+last);
                int s=last*a[i];
                p*=p;
                long double g=(long double)p/(long double)s;
                if (g<ans)
                {
                    ans=g;
                    a1=last;
                    a2=a[i];
                }
            }
            if (a[i]==a[i-1]) last=a[i];
        }
        cout<<a1<<" "<<a1<<" "<<a2<<" "<<a2<<"\n";
    }
}
/**

**/