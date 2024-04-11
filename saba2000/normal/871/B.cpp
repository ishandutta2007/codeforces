////\\//\\//\\//\\//\\//
//\\//\\//\\//\\//\\//\\
////\\//\\//\\//\\//\\//
//\\//\\//\\//\\//\\//\\
////\\//\\//\\//\\//\\//
//\\//\\//\\//\\//\\//\\
////\\//\\//\\//\\//\\//
#include<bits/stdc++.h>
using namespace std;
int x[100009],y[100009],n;
int p[5009],b[5009],f[5009],B[5009],P[5009];
int xorr(int i, int j)
{
    if(j>=i)
        return x[j]^(x[i-1])^(y[j-1])^(y[i-1]);
    else
    if(j==0)
    return x[n-1]^x[i-1]^y[n-1]^y[i-1]^x[j];
    else
        return x[n-1]^x[i-1]^y[n-1]^y[i-1]^x[j]^y[j-1];
    //i,i  x[i]
    //i+1,i y[i]
    //i+1,i+1 x[i+1]
    //i+2,i+1 y[i+1]
    //i+2,i+2  x[i+2]
//a[i]^(a[i+k])
//x[i]^x[i+1]^...^(x[i+k]);
//y[i]^...(y[i+k-1]);
}
main()
{
    cin>>n;
    //b[i]==0
//a[i]^b[j]
//a[i]^b[i]
//b[i]^a[i+1]
//a[i+1]^b[i+1]
//
    for (int i=0; i<n; i++)
    {
        cout<<"? "<<i<<" "<<i<<endl;
        fflush(stdout);
        cin>>x[i];
        cout<<"? "<<(i+1)%n<<" "<<i<<endl;
        fflush(stdout);
        cin>>y[i];
    }
    for(int i=1; i<n; i++)
    x[i]=(x[i]^x[i-1]);
    for (int j=1; j<n; j++)
    y[j]=(y[j]^y[j-1]);
     for (int i=0; i<n; i++)
     {
         int c=0;
         for (int j=0; j<n; j++)
         {//j,i==p[j] b[p[j]]==j
             if((xorr(0,xorr(j,i))^xorr(0,i))!=j) c=1;
         }
         if(c==0)
         {
             for (int j=0; j<n; j++)
                p[j]=xorr(j,i);
             break;
         }
     }
     int ans=0;
     //2 1 0
     for (int i=0; i<n; i++)
        b[p[i]]=i;
    for (int i=0; i<n; i++)
    {
        int c=0;

        for (int j=0; j<n; j++)
            f[j]=0;
        for (int j=0; j<n; j++)
        {
            P[j]=(p[j]^i);
            B[j]=(b[j]^i);
            f[P[j]]++;
        }
        //1 0 3 2   1 0 3 2
        for (int j=0; j<n; j++)
            if(f[j]!=1) c=1; //out<<i<<" "<<j<<endl;

        for (int j=0; j<n; j++)
            if(P[B[j]]!=j ) c=1;
        if(c==0) ans++;

//2 0 1  1 2 0
    }
    cout<<"!"<<endl<<ans<<endl;
    for (int i=0; i<n; i++)
        cout<<p[i]<<" ";
    fflush(stdout);
}