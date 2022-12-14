#include <bits/stdc++.h>
using namespace std;
multiset<pair<long long, int> > S;
int main()
{
    int h,q;
    cin>>h>>q;
    long long N = (1LL<<h)-1;
    long long B = (1LL<<(h-1));
    for (int i=0;i<q;i++)
    {
        long long lev,L,R,ans;
        cin>>lev>>L>>R>>ans;
        for (int j=0;j<h-lev;j++)
            L=L*2,R=R*2+1;
        if (ans==0)
            S.insert(make_pair(B,1)),S.insert(make_pair(L,-1)),S.insert(make_pair(R+1,1)),S.insert(make_pair(N+1,-1));

        else
            S.insert(make_pair(L,1)),S.insert(make_pair(R+1,-1));
    }
    int num=0;
    long long t=0;
    long long last=B-1;
    long long x=-1;
    while(!S.empty())
    {
        pair<long long,int> p = *S.begin();
        S.erase(S.begin());
        if (num==q)t+=p.first-last,x=last;
        num+=p.second;
        last=p.first;
    }
    if (q==0)
    {
        if (h==1)cout<<1<<endl;
        else cout<<"Data not sufficient!"<<endl;
    }
    else if (t==1)
        cout<<x<<endl;
    else if (t==0)
        cout<<"Game cheated!"<<endl;
    else
        cout<<"Data not sufficient!"<<endl;
}