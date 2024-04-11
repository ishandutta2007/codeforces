#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t>0)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=0;
        while (a>0||b>0||c>0)
        {
            if (a>b) swap(a,b);
            if (b>c) swap(b,c);
            if (a>b) swap(a,b);
            if (b==0) break;
            if (b>a)
            {
                ll g=b-a;
                ans+=b-a;
                b-=g;
                c-=g;
            } else
            if (b==c)
            {
                ll d=a/2;
                ans+=d*3;
                a-=d*2;
                b-=d*2;
                c-=d*2;
                if (a==1) ans++;
                a=0;
                b=0;
                c=0;
            } else
            {
                ll d=(c-b)*2;
                d=min(d,b+a);
                ans+=d;
                c-=d;
                a-=d/2;
                b-=(d+1)/2;
                //cout<<"!!"<<endl;
            }
            //cout<<a<<" "<<b<<" "<<c<<" = "<<ans<<endl;
        }
        cout<<ans<<"\n";
        t--;
    }
}
/**
4 7 10
4 4 7 - 3
3 4 6 - 2
3 3 5 - 2
2 3 4 - 1
2 2 3 - 1
1 2 2 - 0
**/