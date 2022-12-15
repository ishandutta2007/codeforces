#include<iostream>

using namespace std;

int main  ()
{
    string s;
    int sum=0;

    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')sum++;
        if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9')sum++;
    }

    cout<<sum<<endl;

    return 0;
}