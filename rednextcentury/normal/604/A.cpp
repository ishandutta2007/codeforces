#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
int m[100];
int w[100];
int val[]={500,1000,1500,2000,2500};
int main()
{
    for (int i=0;i<5;i++)
        cin>>m[i];
    for (int i=0;i<5;i++)
        cin>>w[i];
    double sum=0;
    for (int i=0;i<5;i++)
    {

        sum+=max((val[i]*3)/10.0,(1.0-m[i]/250.0)*val[i]-50*w[i]);
    }
    int a,b;
    cin>>a>>b;
    sum+=a*100-50*b;
    cout<<sum<<endl;
}