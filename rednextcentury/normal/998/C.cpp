#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    int last=-1;
    long long ret=0;
    for (int i=0;i<s.size();i++)
    {
        if ((s[i]-'0')!=last)
        {
            if (last==0)
                ret++;
            last = s[i]-'0';
        }
    }
    ret+=(last==0);
    if (ret==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ret--;
    cout<<ret*min(l,r)+r<<endl;
}