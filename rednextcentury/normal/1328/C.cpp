#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;
        string a="",b="";
        bool first=0;
        for (int i=0;i<n;i++){
            if (s[i]=='2'){
                if (!first)a+="1",b+="1";
                else a+="0",b+="2";
            } else if (s[i]=='0') a+="0", b+="0";
            else {
                if (!first)a+="1",b+="0",first=1;
                else a+="0",b+="1";
            }
        }
        cout<<a<<endl<<b<<endl;
    }
}