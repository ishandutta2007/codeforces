#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int use[N];
int main()
{
    sync;
    #ifdef LOCAL
    #else
    #endif
    int n;
    cin>>n;
    set<int> d,r,dr;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if (ch=='D') d.insert(i); else r.insert(i);
        dr.insert(i);
        if (ch=='D') use[i]=1; else use[i]=2;
    }
    while(1==1)
    {
        if (r.size()==0) {cout<<"D"<<endl; return 0;} else
        if (d.size()==0) {cout<<"R"<<endl; return 0;}
        int k=*dr.begin();
        int p=k%n;
        if (p==0) p=n;
        if (use[p]==1)
        {
            dr.erase((*r.begin()));
            r.erase((*r.begin()));
            d.erase(k);
            dr.erase(k);
            d.insert(k+n);
            dr.insert(k+n);
        } else
        {
            dr.erase((*d.begin()));
            d.erase((*d.begin()));
            r.erase(k);
            dr.erase(k);
            dr.insert(k+n);
            r.insert(k+n);
        }
    }
}