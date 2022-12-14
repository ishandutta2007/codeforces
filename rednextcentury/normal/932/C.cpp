#include<bits/stdc++.h>
using namespace std;
vector<int> ret;
void add(int l,int r)
{
    for (int i=l+1;i<=r;i++)
        ret.push_back(i);
    ret.push_back(l);
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<=n;i++)
    {
        int x = n - a*i;
        if (x<0)break;
        if (x%b==0)
        {
            int y=x/b;
            x=i;
            int l=1;
            while(x--)
            {
                add(l,l+a-1);
                l=l+a;
            }
            while(y--)
            {
                add(l,l+b-1);
                l=l+b;
            }
            for (int i=0;i<n;i++)
                cout<<ret[i]<<' ';
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}