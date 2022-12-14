# include <iostream>
# include <string>
# include <map>
# include <cstdlib>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        int ans=0;
        for (int x=1;x<=12;x++)
        {
            if (12%x==0)
            {
                int y=12/x;
                for (int u=0;u<y;u++)
                {
                bool p=1;
                    for (int c=u;c<12;c+=y)
                    {
                        if (s[c]=='O')
                            p=0;
                    }
                if (p==1)
                {
                    ans++;
                    break;
                }
                }
            }
        }
        cout<<ans;
        for (int x=1;x<=12;x++)
        {
            if (12%x==0)
            {
                int y=12/x;
                for (int u=0;u<y;u++)
                {
                bool p=1;
                    for (int c=u;c<12;c+=y)
                    {
                        if (s[c]=='O')
                            p=0;
                    }
                if (p==1)
                {
                    cout<<" "<<x<<"x"<<y;
                    break;
                }
                }
            }
        }
        cout<<endl;
    }
}