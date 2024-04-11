# include <iostream>
using namespace std;
int before[100];
int after[100];
int main()
{
    int loc1=0,loc2=0;
    int n,p,k;
    cin>>n>>p>>k;
    for (int i=p+1;i<=p+k;i++)
    {
        if (i>n)
            break;
        after[loc2++]=i;
    }
    for (int i=p-1;i>=p-k;i--)
    {
        if (i<1)
            break;
        before[loc1++]=i;
    }
    if (before[loc1-1]!=1 && p!=1)
        cout<<"<<";
    for (int i=loc1-1;i>=0;i--)
        cout<<" "<<before[i];
    cout<<" ("<<p<<")";
    for (int i=0;i<loc2;i++)
        cout<<" "<<after[i];
    if (after[loc2-1]!=n && p!=n)
        cout<<" >>";
    cout<<endl;
}