#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    stack<int> L;
    stack<int> O;
    int ans=0;
    L.push(500);
    O.push(1);
    int S=0;
    for (int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int s;
            cin>>s;
            S=s;
        }
        if(t==2)
        while(O.top()==0) {ans++; O.pop();}
        if(t==3)
        {
            int s;
            cin>>s;
            L.push(s);
        }
        if(t==4)
            O.push(1);
        if(t==5)
            L.push(500);
        if(t==6)
            O.push(0);
        while(S>L.top()) {ans++; L.pop();}
    }
    cout<<ans<<endl;

}