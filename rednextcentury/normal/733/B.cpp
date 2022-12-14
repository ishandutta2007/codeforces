#include<bits/stdc++.h>
using namespace std;
int l[1000000];
int r[1000000];
int main()
{
    int n;
    cin>>n;
    int L=0,R=0;
    for (int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        L+=l[i],R+=r[i];
    }
    int best=abs(L-R),ret=0;
    for (int i=0;i<n;i++)
    {
        if (abs((L-l[i]+r[i])-(R-r[i]+l[i]))>best)
            best=abs((L-l[i]+r[i])-(R-r[i]+l[i])),ret=i+1;

    }
    cout<<ret<<endl;
}