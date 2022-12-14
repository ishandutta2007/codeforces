# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
string d[]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
int m=11;
int main()
{
    int ans=0,n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        char s[1000];
        cin>>s;
        if (s[0]>='0' && s[0]<='9')
        {
            int y=atoi(s);
            if (y<18)
                ans++;
        }
        else
        {
            for (int i=0;i<m;i++)
                if (s==d[i])
                    ans++;
        }
    }
    cout<<ans<<endl;
}