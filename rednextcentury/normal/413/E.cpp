#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[2];
int comp[2][1000000];
int vis[2][1000000];
int n;
void dfs(int i,int j,int col){
    if (i>=2 || j>=n || i<0 || j<0)return;
    if (s[i][j]=='X')return;
    if (vis[i][j])return;
    vis[i][j]=1;
    comp[i][j]=col;
    dfs(i+1,j,col);
    dfs(i,j+1,col);
    dfs(i,j-1,col);
    dfs(i-1,j,col);
}
int L[1000000];
int R[1000000];
int sum[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    int V=0;
    cin>>s[0]>>s[1];
    for (int i=0;i<2;i++){
        for (int j=0;j<n;j++){
            if (!vis[i][j])dfs(i,j,++V);
        }
    }
    if ((s[0][0]=='X')+(s[1][0]=='X')==1)L[0]=0;
    else L[0]=-1;
    if ((s[0].back()=='X')+(s[1].back()=='X')==1)R[n-1]=n-1;
    else R[n-1]=n+1;
    for (int i=1;i<n;i++){
        L[i]=L[i-1];
        if ((s[0][i]=='X')+(s[1][i]=='X')==1)L[i]=i;
    }
    for (int i=n-2;i>=0;i--){
        R[i]=R[i+1];
        if ((s[0][i]=='X')+(s[1][i]=='X')==1)R[i]=i;
    }
    for (int i=0;i<n;i++){
        if (i)sum[i]=sum[i-1];
        if (i && L[i]==i && L[i-1]!=-1 && s[0][L[i-1]]!=s[0][i])sum[i]++;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int x1 = (x-1)/n;
        int y1 = (x-1)%n;
        int x2 = (y-1)/n;
        int y2 = (y-1)%n;
        x = y1;
        y = y2;
        if (y1>y2){
            swap(y1,y2);
            swap(x1,x2);
            swap(x,y);
        }
        if (comp[x1][y1]!=comp[x2][y2]){
            cout<<"-1\n";
        } else {
            if (R[x]>L[y])cout<<y-x+abs(x1-x2)<<endl;
            else {
                int add=0;
                if (x1==0 && s[0][R[x]]=='X')add++;
                if (x1==1 && s[1][R[x]]=='X')add++;
                if (x2==0 && s[0][L[y]]=='X')add++;
                if (x2==1 && s[1][L[y]]=='X')add++;
                cout<<y-x+sum[L[y]]-sum[R[x]]+add<<endl;
            }
        }
    }
}