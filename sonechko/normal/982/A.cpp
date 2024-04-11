#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int kk=0;
    for (int j=0; j<s.size(); j++)
    if (j>0&&s[j]=='1'&&s[j-1]=='1') {cout<<"No"<<endl; return 0;} else
    if (s[j]=='0'&&(j==0||s[j-1]=='0')&&(j==n-1||s[j+1]=='0'))
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
}