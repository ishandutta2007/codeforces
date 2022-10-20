#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n,m;
    string a[150];
    cin>>n>>m;
    int i,j;
    int firstx=-1,firsty=-1;
    int secondx=-1,secondy=-1;
    int thirdx=-1,thirdy=-1;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        }
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]=='*')
                {
                if(firstx==-1){firstx=i;firsty=j;}
                else
                    {
                    if(secondx==-1){secondx=i;secondy=j;}
                    else
                        {
                        thirdx=i;
                        thirdy=j;
                        }
                    }
                }
            }
        }
    int ansx;
    int ansy;
    if(firstx!=secondx && firstx!=thirdx)ansx=firstx;
    if(firstx!=secondx && secondx!=thirdx)ansx=secondx;
    if(thirdx!=secondx && firstx!=thirdx)ansx=thirdx;


    if(firsty!=secondy && firsty!=thirdy)ansy=firsty;
    if(firsty!=secondy && secondy!=thirdy)ansy=secondy;
    if(thirdy!=secondy && firsty!=thirdy)ansy=thirdy;


    printf("%d %d\n",ansx+1,ansy+1);
    return 0;
    }