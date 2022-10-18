#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y1 kdjf

const int N = 4e5 + 11;
const ll MOD = 1e9 + 7;

ll ans;
set<int> st1,st2,st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ans=1;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        ll p;
        cin>>p;
        if (s=="ADD")
        {
            int p1=0,p2=0;
            if (st2.size()>0)
            {
                int x=(*st2.begin());
                if (p<x) p1=1;
            } else p1=1;
            if (st1.size()>0)
            {
                int x=(*st1.rbegin());
                if (p>x) p2=1;
            } else p2=1;
            ///cout<<p1<<" "<<p2<<endl;
            if (p1==1&&p2==1) st.insert(p); else
            if (p1==1) st1.insert(p); else
            if (p2==1) st2.insert(p); else
                ans=0;
        } else
        {
            if (st1.size()>0&&st2.size()>0)
            {
                if ((*st1.rbegin())>(*st2.begin())) ans=0;
            }
            if (st1.find(p)!=st1.end())
            {
                if ((*st1.rbegin())!=p) ans=0; else st1.erase(p);
            } else
            if (st2.find(p)!=st2.end())
            {
                if ((*st2.begin())!=p) ans=0; else st2.erase(p);
            } else
            {
                while (st.size()>0)
                {
                    int l=*st.begin();
                    if (l==p) break;
                    st1.insert(l);
                    st.erase(l);
                }
                while (st.size()>0)
                {
                    int l=*st.rbegin();
                    if (l==p) break;
                    st2.insert(l);
                    st.erase(l);
                }
                if (st1.size()>0&&st2.size()>0)
                {
                    if ((*st1.rbegin())>(*st2.begin())) ans=0;
                }
                st.clear();
                if (st1.size()>0&&p<(*st1.rbegin())) ans=0;
                if (st2.size()>0&&p>(*st2.begin())) ans=0;
                ans=(ans*2ll)%MOD;
            }
            while (st.size()>0)
                {
                    int l=*st.begin();
                    if (l>=p) break;
                    st1.insert(l);
                    st.erase(l);
                }
                while (st.size()>0)
                {
                    int l=*st.rbegin();
                    if (l<=p) break;
                    st2.insert(l);
                    st.erase(l);
                }
        }
    }
    ans=(ans*1ll*(st.size()+1))%MOD;
    cout<<ans<<"\n";
}