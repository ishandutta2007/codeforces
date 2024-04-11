#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        if (s.substr(0,2)=="op")cout<<"FILIPINO"<<endl;
        else if (s.size()>=5 && s.substr(0,5)=="adinm")cout<<"KOREAN"<<endl;
        else cout<<"JAPANESE"<<endl;
    }
}