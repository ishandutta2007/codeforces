#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int n;

int a[100][100];
int c[100];

int x[10000];
int y[10000];


vector <int> a1;
vector <int> a2;
vector <int> a3;
vector <int> a4;



int main()
    {
    scanf("%d",&n);
    int i,j;
    int br=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&c[i]);
        }

    br=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<c[i];j++)
            {
            scanf("%d",&a[i][j]);
            x[a[i][j]]=i;
            y[a[i][j]]=j;
            }
        }
    int k=1;
    a1.clear();
    a2.clear();
    a3.clear();
    a4.clear();
    for(i=0;i<n;i++)
        {
        for(j=0;j<c[i];j++)
            {
            if(a[i][j]!=k)
                {
                a1.push_back(i);
                a2.push_back(j);
                a3.push_back(x[k]);
                a4.push_back(y[k]);
                x[a[i][j]]=x[k];
                y[a[i][j]]=y[k];
                swap(a[i][j],a[x[k]][y[k]]);
                }
            k++;
            }
        }

    printf("%d\n",a1.size());
    for(i=0;i<a1.size();i++)
        {
        printf("%d %d %d %d\n",a1[i]+1,a2[i]+1,a3[i]+1,a4[i]+1);
        }
    return 0;
    }