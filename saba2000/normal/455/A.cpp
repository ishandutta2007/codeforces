#include<iostream>
using namespace std;
int main()
{   long long int  n,a[100002]={0},cot[100002]={0},d[100002]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cot[a[i]]++;
    }
    d[1]=cot[1];d[0]=0;
    for(int i=2;i<=100000;i++)
        d[i]=max(d[i-1],d[i-2]+cot[i]*i);
    cout<<d[100000]<<endl;
    return 0;
}