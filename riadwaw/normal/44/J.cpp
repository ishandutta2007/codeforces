#include <vector>
#include<stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <set>
#define OLOLO if(a[i][j-1]=='a')aa=1;if(a[i][j-1]=='b')bb=1;if(a[i][j-1]=='c')cc=1;if(a[i][j-1]=='d')dd=1;if(a[i-1][j]=='a')aa=1;if(a[i-1][j]=='b')bb=1;if(a[i-1][j]=='c')cc=1;if(a[i-1][j]=='d')dd=1;if(a[i-1][j+1]=='a')aa=1;if(a[i-1][j+1]=='b')bb=1;if(a[i-1][j+1]=='c')cc=1;if(a[i-1][j+1]=='d')dd=1;if(a[i-1][j+2]=='a')aa=1;if(a[i-1][j+2]=='b')bb=1;if(a[i-1][j+2]=='c')cc=1;if(a[i-1][j+2]=='d')dd=1;if(a[i][j+3]=='a')aa++;
#define BUGAGA if(aa==0)a[i][j]='a',a[i][j+1]='a',a[i][j+2]='a';else if(bb==0)a[i][j]='b',a[i][j+1]='b', a[i][j+2]='b';else if(cc==0)a[i][j]='c',a[i][j+1]='c', a[i][j+2]='c';else if(dd==0)a[i][j]='d',a[i][j+1]='d', a[i][j+2]='d';
using namespace std;
char a[10010][10010], o[2];
int main(){
    int aa=0,bb=0,cc=0,dd=0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n+3;i++)
        for(int j=0;j<m+3;j++)
            a[i][j]='0';
    for(int i=1;i<=n;i++){
        for(int  j=1;j<m+1;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=m;j++)
        {
            if(a[i][j]=='b')
            {
                cout<<"NO";
                return 0;
            }
            if(a[i][j]=='w')
            {
                if(a[i][j+1]=='b')
                {
                    if(a[i][j+2]!='w')
                    {
                        cout<<"NO";
                        return 0;
                    }
                    OLOLO;
                    BUGAGA;
                    aa=0;
                    bb=0;
                    cc=0;
                    dd=0;
                    j+=2;
                }
                else
                {
                    if(i+2>n || a[i+1][j]!='b' || a[i+2][j]!='w')
                    {
                        cout<<"NO";
                        return 0;
                    }
                    if(a[i-1][j]!='a' && a[i][j-1]!='a' && a[i][j+1]!='a')
                    {
                        a[i][j]='a';
                        a[i+1][j]='a';
                        a[i+2][j]='a';
                    }
                    else if(a[i-1][j]!='c' && a[i][j-1]!='c' && a[i][j+1]!='c')
                    {
                        a[i][j]='c';
                        a[i+1][j]='c';
                        a[i+2][j]='c';
                    }
                    else if(a[i-1][j]!='d' && a[i][j-1]!='d' && a[i][j+1]!='d')
                    {
                        a[i][j]='d';
                        a[i+1][j]='d';
                        a[i+2][j]='d';
                    }
                }
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}