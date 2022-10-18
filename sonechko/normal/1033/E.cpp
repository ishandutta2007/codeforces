#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define y1 skfn

const int N = 3e6 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

vector<int> v[N];
int use[N];
map<ull,int> mt;
int n;
ull st[N];
int kol;

int get(vector<int> vv)
{
    if ((int)vv.size()==0) return 0;
    if ((int)vv.size()==1) return 0;
    ull c=0;
    for (int j=0; j<vv.size(); j++)
        c+=st[vv[j]];
    if (mt.find(c)!=mt.end()) return mt[c];
    cout<<"? "<<vv.size()<<endl;
    for (int i=0; i<vv.size(); i++)
        cout<<vv[i]<<" ";
    cout<<endl;
    int t;
    cin>>t;
    mt[c]=t;
    return t;
}

int get(vector<int> v1, vector<int> v2)
{
    vector<int> vv;
    for (int j=0; j<v1.size(); j++)
        vv.pb(v1[j]);
    for (int j=0; j<v2.size(); j++)
        vv.pb(v2[j]);
    return get(vv)-get(v1)-get(v2);
}

int findd(vector<int> v1, vector<int> v2, int g)
{
    if (g==0)
    {
        int c=get(v1,v2);
        if (c==0) return -1;
    }
    if ((int)v2.size()==1) return v2[0];
    vector<int> vv1,vv2;
    for (int j=0; j<v2.size(); j++)
        if (j<v2.size()/2) vv1.pb(v2[j]); else vv2.pb(v2[j]);
    int t=findd(v1,vv1,0);
    if (t!=-1) return t;
    return findd(v1,vv2,1);
}

pair<int,int> findd(vector<int> vv)
{
    if (get(vv)==0) return mp(-1,-1);
    if (vv.size()==2) return mp(vv[0],vv[1]);
    vector<int> v1,v2;
    for (int j=0; j<vv.size(); j++)
        if (j<vv.size()/2) v1.pb(vv[j]); else v2.pb(vv[j]);


    pair<int,int> p=findd(v1);
    if (p.ff!=-1) return p;


    p=findd(v2);
    if (p.ff!=-1) return p;


    int c=findd(v1,v2,0);
    vector<int> d;
    d.pb(c);
    int cc=findd(d,v1,1);
    return mp(c,cc);
}


void dfs(int l, int r)
{
    use[l]=r;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j],3-r);
}

vector<int> ans;
vector<int> c;

void dfss(int l, int r)
{
    c.pb(l);
    if (l==r) ans=c;
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfss(v[l][j],r);
    c.pop_back();
}

void noo(vector<int> v)
{
    pair<int,int> p=findd(v);
    int l=p.ff;
    int r=p.ss;
    for (int i=1; i<=n; i++)
        use[i]=0;
    dfss(l,r);
    cout<<"N "<<ans.size()<<endl;
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
        cout<<endl;
        exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    use[1]=1;
    st[0]=1;
    for (int i=1; i<=n; i++)
        st[i]=st[i-1]*11;
    for (int j=1; j<n; j++)
    {
        vector<int> v1,v2;
        for (int i=1; i<=n; i++)
            if (use[i]==1) v1.pb(i); else v2.pb(i);
        int p=findd(v1,v2,0);
        if (p==-1) {//cout<<"new "<<v2[0]<<endl;
        use[v2[0]]=1;} else
        {
            vector<int> d;
            d.pb(p);
            int c=findd(d,v1,1);
            v[c].pb(p);
            v[p].pb(c);
            use[p]=1;
            //cout<<"+ "<<p<<" with "<<c<<endl;
        }
    }
    for (int i=1; i<=n; i++)
        use[i]=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0) dfs(i,1);
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
        if (use[i]==1) v1.pb(i); else v2.pb(i);
    //for (int i=0; i<v1.size(); i++)
    //    cout<<v1[i]<<" ";
    //cout<<endl;
    if (get(v1)!=0) noo(v1);
    if (get(v2)!=0) noo(v2);
    cout<<"Y "<<v1.size()<<endl;
    for (int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;

}
/**

1-2
 \|
4-3
**/