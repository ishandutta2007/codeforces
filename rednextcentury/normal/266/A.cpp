# include <algorithm>
# include <iostream>
using namespace std;
int main ()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int num=0;
    char cur=s[0];
    int ans=0;
    for (int i=0;i<s.size();i++)
    {
        if (cur==s[i])num++;
        else
            ans+=num-1,num=1,cur=s[i];
    }
    cout<<ans+num-1<<endl;
}