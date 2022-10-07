#include<bits/stdc++.h>
using namespace std;
int C[2009];
int M[2009];
main()
{
    long long p,k;
    cin >> p >> k;
    int t= 70;
    while(p>0)
    {
        C[t--]=p%k;
        p/=k;
    }
  t= 71;
  int T = t;
    for (int i=t-1; i>=0; i--)
    {
        int x =  t-1-i;
        if(x%2==0)
        {
            C[i-1] += C[i]/k;
            C[i]%=k;
        }
        else
        {
            int z,x;
            if(C[i]%k==0) z=C[i]/k; else
           z = C[i]/k+1;
             x = z*k-C[i];
            C[i-1]+=z;
            C[i] = abs(x);
        }
        if(C[i]>0) T=i;
    }
    cout<<t-T<<endl;
    for (int i = t-1; i>=T; i--)
        cout<<C[i]<<" ";
    cout<<endl;
}