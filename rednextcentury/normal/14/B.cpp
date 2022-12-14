# include <iostream>
# include <stdio.h>
# include <cstdlib>
# include <set>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int s=0,e=10000000;
    for (int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        if (l>r)
            swap(l,r);
        s=max(s,l);
        e=min(e,r);
    }
    if (s>e)
        cout<<-1<<endl;
    else if (x<=s || x>=e)
        cout<<min(abs(x-s),abs(x-e));
    else
        cout<<0<<endl;
}