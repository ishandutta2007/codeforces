#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
//#define endl "\n"
#define mp make_pair
const int N = 1e5 + 11;
int w[11][N],t[11][N][5],n,use[N];
vector<int> vv;
void update(int l, int r, int x, int k)
{
	for (int i=r; i<=n; i=(i|(i+1)))
		t[l][i][x]+=k;
}
int sum(int l, int r, int x)
{
	int res=0;
	for (int i=r; i>=0; i=(i&(i+1))-1)
		res+=t[l][i][x];
	return res;
}
int sum(int jj, int l, int r, int x)
{
    return sum(jj,r,x)-sum(jj,l-1,x);
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    n=s.size();
    s="."+s;
    for (int jj=1; jj<=10; jj++)
    {
        for (int i=1; i<=n; i++)
            use[i]=0;
        vv.clear();
        for (int i=1; i<=n; i++)
        if (use[i]==0)
        {
            for (int j=i; j<=n; j+=jj)
            {
                vv.pb(j);
                use[j]=1;
            }
        }
        for (int i=0; i<vv.size(); i++)
        {
            w[jj][vv[i]]=i;
        }
        for (int i=0; i<vv.size(); i++)
            if (s[vv[i]]=='A') update(jj,i,1,1); else
            if (s[vv[i]]=='C') update(jj,i,2,1); else
            if (s[vv[i]]=='G') update(jj,i,3,1); else update(jj,i,4,1);
    }
    int m;
    cin>>m;
    for (int jjj=1; jjj<=m; jjj++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int pos;
            char ch;
            cin>>pos>>ch;
            for (int jj=1; jj<=10; jj++)
            {
                int pos2=w[jj][pos];
                if (s[pos]=='A') update(jj,pos2,1,-1); else
                if (s[pos]=='C') update(jj,pos2,2,-1); else
                if (s[pos]=='G') update(jj,pos2,3,-1); else
                                 update(jj,pos2,4,-1);
            }
            s[pos]=ch;
            for (int jj=1; jj<=10; jj++)
            {
                int pos2=w[jj][pos];
                if (s[pos]=='A') update(jj,pos2,1,1); else
                if (s[pos]=='C') update(jj,pos2,2,1); else
                if (s[pos]=='G') update(jj,pos2,3,1); else
                                 update(jj,pos2,4,1);
            }
        } else
        {
            int l,r;
            string t;
            cin>>l>>r>>t;
            int sz=t.size();
            t="."+t;
            int kolr=(r-l+1)/sz;
            int ss=0;
            for (int j=1; j<=sz; j++)
            {
                int p=l+j-1;
                int pp=(kolr-1)*sz+l-1+j;
                if (pp+sz<=r) pp+=sz;
                if (pp+sz<=r) pp+=sz;
                int jj=sz;
                if (p<=pp)
                {
                    if (t[j]=='A') ss+=sum(jj,w[jj][p],w[jj][pp],1); else
                    if (t[j]=='C') ss+=sum(jj,w[jj][p],w[jj][pp],2); else
                    if (t[j]=='G') ss+=sum(jj,w[jj][p],w[jj][pp],3); else
                    ss+=sum(jj,w[jj][p],w[jj][pp],4);
                }
            }
            cout<<ss<<"\n";
        }
    }
}