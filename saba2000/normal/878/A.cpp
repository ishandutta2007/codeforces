#include<bits/stdc++.h>
using namespace std;
bool x[15],y[15];
main()
{
    int n;
    cin>>n;
    for (int i=0; i<10; i++)
    {
        y[i]=1;

    }
    int t=0;
    for (int i=0; i<n; i++)
    {
        char k;
        int p;
        cin>>k>>p;
        for (int i=0; i<10; i++)
        {
            if(k=='|') x[i]=(x[i]|(bool)((1<<i)&p));
             if(k=='&') {x[i]=(x[i]&(bool)((1<<i)&p));t=1;}
              if(k=='^') x[i]=(x[i]^(bool)((1<<i)&p));
            if(k=='|') y[i]=(y[i]|(bool)((1<<i)&p));
             if(k=='&'){y[i]=(y[i]&(bool)((1<<i)&p)); t=1;}
              if(k=='^') y[i]=(y[i]^(bool)((1<<i)&p));

        }
    }
    int A=0,X=0,O=0;
    for (int i=0; i<10; i++)
    {
        if(x[i]==0 && y[i]==0)
        {
            O|=(1<<i);
            X|=(1<<i);
        }
        if(x[i]==1 && y[i]==0) X|=(1<<i);
        if(x[i]==1 && y[i]==1) O|=(1<<i);
    }
    if(t==1) cout<<3<<endl<<"| "<<O<<endl<<"& "<<1023<<endl<<"^ "<<X<<endl;
   else cout<<2<<endl<<"| "<<O<<endl<<"^ "<<X<<endl;
}