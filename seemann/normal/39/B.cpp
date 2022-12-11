#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int n,k=0,q=1,x;
    int ans[500];
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>x;
        if (x==q) {
            ans[k++]=i+2001;
            q++;
        }
    }
    cout<<k<<'\n';
    for (int i=0;i<k;i++) cout<<ans[i]<<' ';
    return 0;
}