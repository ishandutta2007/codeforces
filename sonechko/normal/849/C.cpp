#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 11;
#define pb push_back
int main()
{
    int k;
    cin>>k;
    if (k==0) {cout<<"a"<<endl; return 0;}
    string s="";
    vector<int> v;
    for (int j=2; j<=10000; j++)
    v.pb(j*(j-1)/2);
    char ch='a';
    for (int i=v.size()-1; i>=0; i--)
        while
            (v[i]<=k)
        {
            for (int p=1; p<=i+2; p++)
            {
                s=s+".";
                s[s.size()-1]=ch;
            }
            k-=v[i];
            ch++;
        }
    cout<<s<<endl;
}