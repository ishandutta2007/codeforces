#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int d=b,ans=0;
    for (int i=1; i<=k; i++)
    {
        if (i%2==1)
        {
            if (d-f<0) {cout<<-1<<endl; return 0;} else
            if (b-(a-f)<0) {cout<<-1<<endl; return 0;} else
            if (d-(a+a-f)>=0) {d-=a;} else
            if (i==k&&d>=a) {d-=a;} else
            {
                d=b-(a-f);
                ans++;
            }
        } else
        {
            if (d-(a-f)<0) {cout<<-1<<endl; return 0;} else
            if (b-f<0) {cout<<-1<<endl; return 0;} else
            if (d-(a+f)>=0) {d-=a;} else
            if (i==k&&d>=a) {d-=a;} else
            {
                d=b-f;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}