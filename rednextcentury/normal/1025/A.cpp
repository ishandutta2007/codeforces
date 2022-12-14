#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if (n==1) {
        cout<<"Yes"<<endl;
        return 0;
    }
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for (int i=1;i<n;i++) {
        if (s[i]==s[i-1]) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

}