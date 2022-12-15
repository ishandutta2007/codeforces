#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int x[1001];
double d[1001];

int main ()
{
    int n,r,i,j;
    double maxi,p;

    cin>>n>>r;

    for(i=0;i<n;i++)
    {
        cin>>x[i];
    }

    for(i=0;i<n;i++)
    {
        maxi=(double)r;
        for(j=0;j<i;j++)
        {
            if(abs(x[i]-x[j])>2*r)continue;

            p=(double)sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j]));
            p+=(double)d[j];
            if(p>maxi)maxi=p;
        }
        d[i]=(double)maxi;
        //cout<<d[i]<<endl;
    }

    for(i=0;i<n-1;i++)
    {
        printf("%f ",d[i]);
    }
    printf("%f\n",d[i]);


    return 0;
}