#include<bits/stdc++.h>
using namespace std;



int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int T=1;
    string s;
    for (int i=1; i<=10000; i++)
    {
        if ((i&1)==1) cout<<"next 0 1"<<endl; else cout<<"next 0"<<endl;
        cin>>T;
        for (int i=1; i<=T; i++)
            {
                cin>>s;
            }
        if (T==2&&i%2==0) break;
    }

    int time_passed = 0;

    while (1)
    {
        time_passed++;

        assert(time_passed <= 5000);

        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cin>>T;
        for (int i=1; i<=T; i++)
        {
            cin>>s;
        }
        if (T==1) break;
    }
    cout<<"done"<<endl;
}