#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int get(int l, int r)
{
    cout<<l<<" "<<r<<endl;
    string s;
    cin>>s;
    if (s[0]=='b') return 1; else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int t=get(0,0);
    ll l=0,t1=t,r=1000000001,t2=(1-t);
    for (int i=2; i<=n; i++)
    {
        ll mid=(l+r)/2;
        if (r-l==2)
        {
            int t=get(1,mid);
            if (t==t1) {cout<<1<<" "<<mid+1<<" "<<0<<" "<<mid<<endl; return 0;}
            cout<<1<<" "<<mid-1<<" "<<0<<" "<<mid<<endl;
            return 0;
        }
        if (r-l==3)
        {
            int t=get(1,mid);
            if (t==t1) {cout<<1<<" "<<mid+1<<" "<<0<<" "<<mid+1<<endl; return 0;}
            cout<<1<<" "<<l<<" "<<0<<" "<<l+1<<endl;
            return 0;
        }
        int t=get(0,mid);
        //cout<<"! "<<l<<".."<<r<<" - "<<mid<<endl;
        if (t==t1) l=mid; else r=mid;
    }
    cout<<1<<" "<<l+1<<" "<<0<<" "<<l+1<<endl;
    //cout<<"!!! "<<l<<endl;
    //cout<<"!!! "<<r<<endl;
}