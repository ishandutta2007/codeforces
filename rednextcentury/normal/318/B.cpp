# include <iostream>
# include <string>
using namespace std;
string s;
int main()
{
    long long ans=0;
    long long now=0;
    cin>>s;
    for (int i=0;i<(int)s.length()-4;i++)
    {
        string b=s.substr(i,5);
        
        if (b=="heavy")
            now++;
        else
            if (b=="metal")
                ans+=now;
    
    }
    cout<<ans<<endl;
}