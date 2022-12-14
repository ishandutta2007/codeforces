# include <iostream>
# include <map>
# include <string>
# include <algorithm>
using namespace std;
int a[100000];
int main()
{
    int n;
    cin>>n;
    for (int d=0;d<n;d++)
        cin>>a[d];
    int i=0,j=n-1,x=0;
    int ans[2]={0};
    while (i<=j)
    {
        if (a[i]>a[j])
        {
            ans[x]+=a[i];
            i++;
        }
        else
        {
            ans[x]+=a[j];
            j--;
        }
        x=1-x;
        
    }
    cout<<ans[0]<<" "<<ans[1]<<endl;
}