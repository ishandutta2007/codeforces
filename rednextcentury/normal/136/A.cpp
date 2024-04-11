# include <algorithm>
# include <iostream>
using namespace std;
int ret[100000];
int main ()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ret[x]=i;
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}