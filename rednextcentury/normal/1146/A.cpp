#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int A=0;
    for (int i=0;i<s.size();i++)
    {

        if (s[i]=='a')A++;
    }
    while(A*2<=n)n--;
    cout<<n<<endl;
}