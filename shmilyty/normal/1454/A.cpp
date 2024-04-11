#include <iostream>
using namespace std;
int n,m;
int main()
{
    cin>>n;
    n+=1;
    while(--n)
    {
    	cin>>m;
        cout<<m<<" ";
        for(int i=1;i<m;++i)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}