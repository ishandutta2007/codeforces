#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int p=0;
    int l=-1;
    for (int j=0; j<s.size(); j++)
    if (p==0&&s[j]=='[') p=1; else
    if (p==1&&s[j]==':') {p=2; l=j+1; break;}
    if (p!=2) {cout<<-1<<endl; return 0;}
    int r=-1;
    p=0;
    for (int j=s.size()-1; j>=0; j--)
    if (p==0&&s[j]==']') p=1; else
    if (p==1&&s[j]==':') {p=2; r=j-1; break;}
    if (p!=2) {cout<<-1<<endl; return 0;}
    if (l>r&&l-r>=2) {cout<<-1<<endl; return 0;}
    int ans=0;
    for (int i=l; i<=r; i++)
    if (s[i]=='|') ans++;
    cout<<ans+4<<endl;
}