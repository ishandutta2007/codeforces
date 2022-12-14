#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    n=n*2;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ret=0;
    for (int i=0;i<n;i++)
        for (int j=i+2;j<n;j++)
            if (a[i]==a[j])
                for (int x=j;x>i+1;x--)
                    swap(a[x],a[x-1]),ret++;
    cout<<ret<<endl;
}