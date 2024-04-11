#include <bits/stdc++.h>
using namespace std;
bool pal(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return s==t;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0;i<100;i++)
    {
        if (pal(s))
        {
            cout<<"YES"<<endl;
            return 0;
        }
        s="0"+s;
    }
    cout<<"NO"<<endl;
}