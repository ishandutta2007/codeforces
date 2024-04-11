#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    if (s.size()==1) {cout<<0<<endl; return 0;}
    int sum=0;
    for (int i=0; i<s.size(); i++)
    {
        sum+=(s[i]-'0');
    }
    int kol=1;
    while (sum>9)
    {
        int p=0;
        while (sum>0)
        {
            p+=sum%10;
            sum/=10;
        }
        sum=p;
        kol++;
    }
    cout<<kol<<endl;
}