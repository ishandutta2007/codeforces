#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int a[1010][1010];
int use[5];
int ansi[500000],ansj[500000],anso[500000];
int ansk=1;
int ans[1010][1010];

void fail()
{
    cout<<"NO";
    exit(0);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,colb=0,colw=0;
    int w=-1,b=-2;
    char c;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            cin>>c;
            if (c=='.') a[i][j]=0;
            else{
                if (c=='w') {
                    colw++;
                    a[i][j]=w;
                }else{
                    colb++;
                    a[i][j]=b;
                }
            }
        }
    if (2*colb!=colw) fail();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            if (a[i][j]==b) {
                if ((j==0)||(j==m-1)||(a[i][j-1]!=w)||(a[i][j+1]!=w)) fail();
                ansi[ansk]=i;
                ansj[ansk]=j;
                anso[ansk]=0;
                a[i][j-1]=ansk;
                a[i][j]=ansk;
                a[i][j+1]=ansk++;
            }
         for (int j=0;j<m;j++)
            if (a[i][j]==w) {
                if ((i>n-3)||(a[i+1][j]!=b)||(a[i+2][j]!=w)) fail();
                ansi[ansk]=i+1;
                ansj[ansk]=j;
                anso[ansk]=1;
                a[i][j]=ansk;
                a[i+1][j]=ansk;
                a[i+2][j]=ansk++;
            }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) ans[i][j]=0;
    for (int i=1;i<ansk;i++) {
        for (int j=1;j<=4;j++) use[j]=0;
        int ii=ansi[i],jj=ansj[i];
        if (anso[i]==0) {
            if (ii>0) use[ans[ii-1][jj]]=1;
            if (ii<n-1) use[ans[ii+1][jj]]=1;
            if ((ii>0)&&(jj>0)) use[ans[ii-1][jj-1]]=1;
            if ((ii<n-1)&&(jj>0)) use[ans[ii+1][jj-1]]=1;
            if ((ii>0)&&(jj<m-1)) use[ans[ii-1][jj+1]]=1;
            if ((ii<n-1)&&(jj<m-1)) use[ans[ii+1][jj+1]]=1;
            if (jj>1) use[ans[ii][jj-2]]=1;
            if (jj<m-2) use[ans[ii][jj+2]]=1;
        }else{
            if (ii>1) use[ans[ii-2][jj]]=1;
            if (ii<n-2) use[ans[ii+2][jj]]=1;
            if ((ii>0)&&(jj>0)) use[ans[ii-1][jj-1]]=1;
            if ((ii<n-1)&&(jj>0)) use[ans[ii+1][jj-1]]=1;
            if ((ii>0)&&(jj<m-1)) use[ans[ii-1][jj+1]]=1;
            if ((ii<n-1)&&(jj<m-1)) use[ans[ii+1][jj+1]]=1;
            if (jj>0) use[ans[ii][jj-1]]=1;
            if (jj<m-1) use[ans[ii][jj+1]]=1;
        }
        int q=1;
        while ((q<5)&&(use[q]==1)) q++;
        if (q==5) fail();
        if (anso[i]==0){
            ans[ii][jj]=q;
            ans[ii][jj-1]=q;
            ans[ii][jj+1]=q;
        }else{
            ans[ii][jj]=q;
            ans[ii-1][jj]=q;
            ans[ii+1][jj]=q;
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) {
            if (ans[i][j]==0) cout<<'.';
            if (ans[i][j]==1) cout<<'a';
            if (ans[i][j]==2) cout<<'b';
            if (ans[i][j]==3) cout<<'c';
            if (ans[i][j]==4) cout<<'d';
        }
        cout<<'\n';
    }
    return 0;
}