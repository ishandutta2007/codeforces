#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

const int N = 1e5 + 11;

int glava[N],sz[N],a[N];
vector<pair<int,int> > vv;
int gl(int l)
{
    if (l==glava[l]) return l;
    return glava[l]=gl(glava[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    multiset<int> st;
    int rr=0,kk=0;
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j].ss;
        if (l!=1&&a[l-1]<a[l]&&l!=n&&a[l+1]<a[l])
        {
            int g1=gl(l-1);
            int g2=gl(l+1);
            st.erase(st.find(sz[g1]));
            st.erase(st.find(sz[g2]));
            glava[g1]=l;
            glava[g2]=l;
            glava[l]=l;
            sz[l]=sz[g1]+sz[g2]+1;
            st.insert(sz[l]);
        } else
        if (l!=1&&a[l-1]<a[l])
        {
            int g1=gl(l-1);
            st.erase(st.find(sz[g1]));
            glava[g1]=l;
            glava[l]=l;
            sz[l]=sz[g1]+1;
            st.insert(sz[l]);
        } else
        if (l!=n&&a[l+1]<a[l])
        {
            int g1=gl(l+1);
            st.erase(st.find(sz[g1]));
            glava[g1]=l;
            glava[l]=l;
            sz[l]=sz[g1]+1;
            st.insert(sz[l]);
        } else
        {
            glava[l]=l;
            sz[l]=1;
            st.insert(sz[l]);
        }
        int p1=*st.begin(),p2=*st.rbegin();
        if (p1==p2)
        {
            if (st.size()>rr) {rr=st.size(); kk=vv[j].ff+1;}
        }
    }
    cout<<kk<<endl;
}