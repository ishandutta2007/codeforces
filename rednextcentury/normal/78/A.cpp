
# include <iostream>
# include <string>
# include <cstdlib>
#define EPS 1e-9
using namespace std;
int syl(string s)
{
    int ret=0;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        if (s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='a' || s[i]=='u')
            ret++;
    }
    return ret;
}
int main()
{
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    if (syl(a)==5 && syl(b)==7 && syl(c)==5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}