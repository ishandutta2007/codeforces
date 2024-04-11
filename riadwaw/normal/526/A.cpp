#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t;
    bool ans=true;
    string s;
    cin>>n>>s;
    int l=n;
    int l4=l/4,l3=l-3;
    for(int k=0;k<l-3;k++)
    {
        for(int i=1;i<=l4;i++)
        {
            ans=true;
            t=0;
            for(int j=k;t<5 && j<l;j+=i,t++)
            {
                if(s[j]=='.'){ans=false;break;}
            }
            if(ans && t== 5){cout<<"yes\n";return 0;}
        }
    }
    cout<<"no";
    return 0;
}