#include<bits/stdc++.h>
using namespace std;
#define ll long long
string best;
int id;
void Try(string s, int k){
    int n = s.size();
    string ret="";
    for (int i=k;i<n;i++)ret+=s[i];
    if (n%2 == k%2){
        for (int i=0;i<k;i++)ret+=s[i];
    } else {

        for (int i=k-1;i>=0;i--)ret+=s[i];
    }
    if (ret<best)best=ret, id = k;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        best=s;
        id=0;
        for (int i=1;i<=n;i++)Try(s,i);
        cout<<best<<endl<<id+1<<endl;
    }
}