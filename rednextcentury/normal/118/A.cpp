# include <string>
# include <iostream>
using namespace std;
int main ()
{
string s;
cin>>s;
if (tolower(s[0])!='a' && tolower(s[0])!='e' && tolower(s[0])!='o' && tolower(s[0])!='u' && tolower(s[0])!='i' && tolower(s[0])!='y')
    cout<<".";
for (int i=0;i<s.length();i++)
{
    if (tolower(s[i])!='a' && tolower(s[i])!='e' && tolower(s[i])!='o' && tolower(s[i])!='u' && tolower(s[i])!='i' && tolower(s[i])!='y')
        cout<<char (tolower(s[i]));
    if (i+1<s.length() && tolower(s[i+1])!='a' && tolower(s[i+1])!='e' && tolower(s[i+1])!='o' && tolower(s[i+1])!='u' && tolower(s[i+1])!='i' && tolower(s[i+1])!='y')
        cout<<".";


}
cout<<endl;
}