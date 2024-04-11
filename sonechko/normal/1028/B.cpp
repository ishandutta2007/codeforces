#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l,r;
    cin>>l>>r;
    string s="",t="";
    int s1=0,s2=0;
    s+="5";
    t+="5";
    s1+=5;
    s2+=5;
    while (s1<l||s2<l)
    {
        s1+=5;
        s2+=4;
        s+="5";
        t+="4";
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    cout<<s<<"\n"<<t<<"\n";
}