#include<bits/stdc++.h>
using namespace std;
int h1[250],h2[250],used[250],a[250];
int n,s1=0,s2=0,br1=0,br2=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i=1;i<=n*2;i++)cin>>a[i],used[a[i]]++;
    for(int i=10;i<100;i++)
    {
        if(used[i]>1)
        {
            s1+=used[i]/2;s2+=used[i]/2;
            h1[i]=used[i]/2;h2[i]=used[i]/2;
            if(used[i]%2)
            {
                if(s1<s2){s1++;h1[i]++;}
                else{s2++;h2[i]++;}
            }
            used[i]=0;
        }
    }
    for(int i=10;i<100;i++)
    {
        if(used[i])
        {
            if(s1<s2){s1++;h1[i]++;}
            else{s2++;h2[i]++;}
        }
    }
    for(int i=10;i<100;i++)
    {
        if(h1[i])br1++;
        if(h2[i])br2++;
    }
    cout<<br1*br2<<"\n";
    for(int i=1;i<=n*2;i++)
    {
        if(h1[a[i]]){cout<<1<<" ";h1[a[i]]--;}
        else {cout<<2<<" ";h2[a[i]]--;}
    }
    cout<<"\n";
    return 0;
}