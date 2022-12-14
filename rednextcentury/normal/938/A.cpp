#include<bits/stdc++.h>
using namespace std;
bool vowel(char s)
{
    return s=='a' || s=='e' || s=='o' || s=='u' || s=='i' || s=='y';
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string b="";
    for (int i=0;i<s.size();i++)
    {
        if (vowel(s[i]))
        {
            if (b.size()==0)
                b+=s[i];
            else if (vowel(b[b.size()-1]))
                continue;
            else
                b+=s[i];
        }
        else
            b+=s[i];
    }
    cout<<b<<endl;
}