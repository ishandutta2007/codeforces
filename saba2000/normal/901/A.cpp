#include<bits/stdc++.h>
using namespace std;
int a[200009];
main()
{
    int h;
    cin>>h;
    h++;
    int fl=0;
    for (int i=0; i<h; i++)
       {
           cin>>a[i];
        if(a[i-1]!=1 && a[i]!=1) fl=1;}
        if(fl==0) {
            cout<<"perfect"<<endl;
            return 0;
        }
        cout<<"ambiguous"<<endl;
        int k=0;
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<a[i]; j++)
                cout<<k<<" ";
            k+=a[i];
        }
        cout<<endl;
         k=0;int p=-1;
        for (int i=0; i<h; i++)
        {
            if(p==-1)
           {for (int j=0; j<a[i]; j++)
                cout<<k<<" ";
           }
                else
                {
                    for (int j=0; j<a[i]-1; j++)
                        cout<<k<<" ";
                    cout<<k-1<<" ";
                }
                k+=a[i];
                if(a[i]>1) p=1;
                else p=-1;
        }
        cout<<endl;


}