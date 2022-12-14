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
        int numZeros=0;
        for (auto x:s)if (x=='0')numZeros++;
        while(s.size() && s.back()=='0')s.pop_back(),numZeros--;
        reverse(s.begin(),s.end());
        while(s.size() && s.back()=='0')s.pop_back(),numZeros--;
        cout<<numZeros<<endl;

    }
}