#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 1e4;

bitset<N+5> b[1005];
int p[N+5];
int n;
vector<int> vv;


void up(int x)
{
    cout<<x/2<<endl;
    vector<int> c;
    for (int i=n; i>=1; i--)
    {
        for (int j=0; j<vv.size(); j++)
        if (b[i-1][x-vv[j]]) {c.pb(vv[j]); x-=vv[j]; break;}
    }
    set<pair<int,int> > st;
    for (int i=0; i<c.size(); i++)
        st.insert(mp(c[i],i+1));
    while (st.size()>0)
    {
        pair<int,int> p=*st.rbegin();
        st.erase(p);
        int kol=p.ff;
        vector<pair<int,int> > vs;
        for (int j=1; j<=kol; j++)
        {
            pair<int,int> p2=*st.rbegin();
            st.erase(p2);
            cout<<p.ss<<" "<<p2.ss<<"\n";
            p2.ff--;
            if (p2.ff>0) vs.pb(p2);
        }
        for (int j=0; j<vs.size(); j++)
            st.insert(vs[j]);
    }
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    p[1]=1;
    for (int i=2; i<=N; i++)
        if (p[i]==0&&i<=1000)
    {
        for (int j=i*i; j<=N; j+=i)
            p[j]=1;
    }
    for (int i=2; i<=n-1; i++)
        if (p[i]==0) vv.pb(i);
    b[0][0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int p=0; p<vv.size(); p++)
            b[i]|=(b[i-1]<<vv[p]);
    }
    for (int i=2; i<N; i++)
        if (i%2==0&&p[i/2]==0)
        {
            if (b[n][i]) up(i);
        }
    cout<<-1<<"\n";
}

/**
n prost so than ( sum of them )/2 = prost


**/