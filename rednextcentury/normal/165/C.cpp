# include <iostream>
# include <string>
using namespace std;
int a[3000000];
int main()
{
    int k;string s;
    cin>>k>>s;
    long long ans=0;
    a[0]=1;
    long long now=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='1')
        now++;
        if (now-k>=0)
          ans+=a[now-k];
        a[now]++;
    }
    cout<<ans<<endl;
}