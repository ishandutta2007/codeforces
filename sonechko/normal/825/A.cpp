#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=s;
    int kol=0;
    for (int i=0; i<s.size(); i++)
    if (s[i]=='0')
    {
        cout<<kol;
        kol=0;
    } else kol++;
    cout<<kol<<endl;
}