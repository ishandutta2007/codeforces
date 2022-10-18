#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ins insert
#define mp make_pair
#define ff first
#define y1 kdhfjse
#define ss second
#define out(l) cout.precision(l); cout<<fixed
const int N = 2000 + 10;
char a[N][N];
int use[N][N][4];
vector<int> l1,r1,kk,ans;
bool gett(int l, int r, int k, int p)
{
    if (p==1)
    {
        if (a[l][r]=='+') return true; else
        if (a[l][r]=='-'&&k%2==1) return true; else
        if (a[l][r]=='|'&&k%2==0) return true; else
        if (a[l][r]=='^'&&k==0) return true; else
        if (a[l][r]=='>'&&k==3) return true; else
        if (a[l][r]=='v'&&k==2) return true; else
        if (a[l][r]=='<'&&k==1) return true; else
        if (a[l][r]=='L'&&k!=1) return true; else
        if (a[l][r]=='R'&&k!=3) return true; else
        if (a[l][r]=='U'&&k!=0) return true; else
        if (a[l][r]=='D'&&k!=2) return true;
    }
    if (p==2)
    {
        if (a[l][r]=='+') return true; else
        if (a[l][r]=='-'&&k%2==0) return true; else
        if (a[l][r]=='|'&&k%2==1) return true; else
        if (a[l][r]=='^'&&k==1) return true; else
        if (a[l][r]=='>'&&k==0) return true; else
        if (a[l][r]=='v'&&k==3) return true; else
        if (a[l][r]=='<'&&k==2) return true; else
        if (a[l][r]=='L'&&k!=2) return true; else
        if (a[l][r]=='R'&&k!=0) return true; else
        if (a[l][r]=='U'&&k!=1) return true; else
        if (a[l][r]=='D'&&k!=3) return true;
    }
    if (p==3)
    {
        if (a[l][r]=='+') return true; else
        if (a[l][r]=='-'&&k%2==1) return true; else
        if (a[l][r]=='|'&&k%2==0) return true; else
        if (a[l][r]=='^'&&k==2) return true; else
        if (a[l][r]=='>'&&k==1) return true; else
        if (a[l][r]=='v'&&k==0) return true; else
        if (a[l][r]=='<'&&k==3) return true; else
        if (a[l][r]=='L'&&k!=3) return true; else
        if (a[l][r]=='R'&&k!=1) return true; else
        if (a[l][r]=='U'&&k!=2) return true; else
        if (a[l][r]=='D'&&k!=0) return true;
    }
    if (p==4)
    {
        if (a[l][r]=='+') return true; else
        if (a[l][r]=='-'&&k%2==0) return true; else
        if (a[l][r]=='|'&&k%2==1) return true; else
        if (a[l][r]=='^'&&k==3) return true; else
        if (a[l][r]=='>'&&k==2) return true; else
        if (a[l][r]=='v'&&k==1) return true; else
        if (a[l][r]=='<'&&k==0) return true; else
        if (a[l][r]=='L'&&k!=0) return true; else
        if (a[l][r]=='R'&&k!=2) return true; else
        if (a[l][r]=='U'&&k!=3) return true; else
        if (a[l][r]=='D'&&k!=1) return true;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    use[x1][y1][0]=1;
    int k1=0,k2=0;
    l1.pb(x1);
    r1.pb(y1);
    kk.pb(0);
    ans.pb(0);
    while (k1<=k2)
    {
        int l=l1[k1],r=r1[k1],k=kk[k1],res=ans[k1];
        k1++;
        if (l==x2&&r==y2) {cout<<res<<endl; return 0;}
        if (use[l][r][(k+1)%4]==0) {use[l][r][(k+1)%4]=1; k2++; l1.pb(l); r1.pb(r); kk.pb((k+1)%4); ans.pb(res+1);}
        if (l>1&&use[l-1][r][k]==0&&gett(l,r,k,1)&&gett(l-1,r,k,3)) {use[l-1][r][k]=1; k2++; l1.pb(l-1); r1.pb(r); kk.pb(k); ans.pb(res+1);}
        if (l<n&&use[l+1][r][k]==0&&gett(l,r,k,3)&&gett(l+1,r,k,1)) {use[l+1][r][k]=1; k2++; l1.pb(l+1); r1.pb(r); kk.pb(k); ans.pb(res+1);}
        if (r>1&&use[l][r-1][k]==0&&gett(l,r,k,4)&&gett(l,r-1,k,2)) {use[l][r-1][k]=1; k2++; l1.pb(l); r1.pb(r-1); kk.pb(k); ans.pb(res+1);}
        if (r<m&&use[l][r+1][k]==0&&gett(l,r,k,2)&&gett(l,r+1,k,4)) {use[l][r+1][k]=1; k2++; l1.pb(l); r1.pb(r+1); kk.pb(k); ans.pb(res+1);}
    }
    cout<<-1<<endl;
}