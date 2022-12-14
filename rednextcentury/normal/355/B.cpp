#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int a[10000];
int b[10000];
int c1,c2,c3,c4;
int solve2(int a[],int n)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=min(c2,c1*a[i]);
    }
    return min(sum,c3); 
}
int main()
{
    cin>>c1>>c2>>c3>>c4;
    int bus,trolley;
    cin>>bus>>trolley;
    int ansb=0;
    int anst=0;
    for (int i=0;i<bus;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<trolley;i++)
    {
        cin>>b[i];
    }
    anst=solve2(b,trolley);
    ansb=solve2(a,bus);
    
    cout<<min(ansb+anst,c4)<<endl;
}