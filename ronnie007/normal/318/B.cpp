#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    string h;
    string metal="metal";
    string heavy="heavy";
    cin>>a;
    int n=a.size();
    int i;
    int br=0;
    long long ans=0;
    for(i=n-1;i>=4;i--)
        {
        h=a[i-4];
        ///cout<<h<<"\n";
        h+=a[i-3];
        ///cout<<h<<"\n";
        h+=a[i-2];
        ///cout<<h<<"\n";
        h+=a[i-1];
        ///cout<<h<<"\n";
        h+=a[i];
        ///cout<<h<<"\n";
        if(h==metal)br++;
        if(h==heavy)ans+=br;
        }
    printf("%I64d\n",ans);
    return 0;
    }