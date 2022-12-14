#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int curMex=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (x>curMex)
        {
            cout<<i<<endl;
            return 0;
        }
        curMex=max(curMex,x+1);
    }
    cout<<-1<<endl;
}