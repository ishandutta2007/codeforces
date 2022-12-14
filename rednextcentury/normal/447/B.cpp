# include <iostream>
# include <string>
using namespace std;
string s;
int val;
char c;
long long ans=0;
int a[26];
int main()
{
    string s;
    int k;
    cin>>s>>k;
    int n=s.length();
    for (int i=0;i<26;i++)
    {
        cin>>a[i];
        if (a[i]>val)
        {
            val=a[i];
            c=char(i+'a');
        }
    }
    for (int i=0;i<n;i++)
    {
        ans+=(i+1)*a[int(s[i]-'a')];
    }
    for (int i=0;i<k;i++)
    {
        ans+=(i+n+1)*val;
    }
    cout<<ans<<endl;
}