#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int ret=0;
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]=='a' || s[i]=='e'  || s[i]=='i' || s[i]=='o' ||s[i]=='u')
            ret++;
        else if (s[i]>='0' && s[i]<='9' && (s[i]-'0')%2)
            ret++;
    }
    cout<<ret<<endl;
}