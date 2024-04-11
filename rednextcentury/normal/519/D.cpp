# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
int val[26];
long long sum[1000000];
map<long long,int> mp[26];
int main()
{
    string s;;
    for (int i=0;i<26;i++)
        cin>>val[i];
    string h;
    cin>>h;
    s="."+h;
    long long ans=0;
    int n=s.length();
    for (int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+val[(int)s[i]-'a'];
        ans+=mp[(int)s[i]-'a'][sum[i-1]];
            mp[(int)s[i]-'a'][sum[i]]++;
    }
    cout<<ans<<endl;
}