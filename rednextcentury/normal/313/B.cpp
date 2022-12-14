# include <iostream>
# include <string>
using namespace std;
struct abokiki
{
int a[1000000];
string b;


};
abokiki n;
int main()
{
    cin>>n.b;
    for (int i=0;i<n.b.length()-1;i++)
    {
        if (n.b[i]==n.b[i+1])
            n.a[i]++;
    
    }
    for (int i=1;i<n.b.length()-1;i++)
    {
        n.a[i]+=n.a[i-1];
    
    }

    int l,r;
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        cin>>l>>r;
        if (l==1)
            cout<<n.a[r-2]<<endl;
        else
            cout<<n.a[r-2]-n.a[l-2]<<endl;
    
    }
}