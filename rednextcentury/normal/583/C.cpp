# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <set>
using namespace std;
multiset<int> s;
int GCD (int a,int b)
{
    if (a%b==0)
        return b;
    if (b%a==0)
        return a;
    return GCD(b%a,a);
}
int ret[1000000];
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n*n;i++)
        cin>>a[i],s.insert(a[i]);
    for (int i=0;i<n;i++)
    {
        int h=s.size();
        multiset<int>::iterator it=s.end();
        it--;
        ret[i]=*it;
        for (int j=0;j<=i;j++)
        {
            int x=GCD(ret[i],ret[j]);
            s.erase(s.find(x));
            if (i!=j)
            s.erase(s.find(x));
        }
    }
    for (int i=0;i<n;i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}