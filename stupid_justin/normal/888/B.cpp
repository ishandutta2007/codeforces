#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int l,r,u,d;
int main() 
{
    cin>>n;
    cin >> str;
    
    for (int i=0;i<str.length();i++)
    {
    	if (str[i]=='L') l++;
        if (str[i]=='R') r++;
        if (str[i]=='U') u++;
        if (str[i]=='D') d++;
	}   
    cout<<2*(min(l,r)+min(u,d))<<endl;
}