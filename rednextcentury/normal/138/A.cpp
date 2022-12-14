#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[50];
string t[50];
bool vowel(char x){
    return x=='a' || x=='e' || x=='o' || x=='i' || x=='u';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int aabb=0,abab=0,abba=0,aaaa=0;
    for (int i=1;i<=n;i++){
        bool ok = 1;
        for (int j=0;j<4;j++) {
            cin>>s[j];
            t[j] = "";
            int num=0;
            for (int x=s[j].size()-1;x>=0;x--){
                t[j]+=s[j][x];
                num+=vowel(s[j][x]);
                if (num==k) break;
            }
            if (num<k)ok=0;
        }
        if (!ok){
            cout<<"NO"<<endl;
            return 0;
        }
        if (t[0]==t[1] && t[2]==t[3])aabb++;
        if (t[0]==t[2] && t[1]==t[3])abab++;
        if (t[0]==t[3] && t[1]==t[2])abba++;
        if (t[0]==t[1] && t[1]==t[2] && t[2]==t[3] && t[3]==t[0])aaaa++;
    }
    if (aaaa==n)cout<<"aaaa"<<endl;
    else if (aabb==n)cout<<"aabb"<<endl;
    else if (abab==n)cout<<"abab"<<endl;
    else if (abba==n)cout<<"abba"<<endl;
    else cout<<"NO"<<endl;
}