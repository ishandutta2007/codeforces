#include <bits/stdc++.h>
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        string a,b;
        cin>>a>>b;
        int l=0;
        bool ok=1;
        for (int j=0;j<a.size();j++) {
            if (l<b.size() && a[j]==b[l]) {
                l++;
                continue;
            } else {
                while (j>0 && l<b.size() && a[j-1]==b[l])
                    l++;
                if (l<b.size() && a[j]==b[l]) {
                    l++;
                    continue;
                }
            }
            ok=0;
            break;
        }
        while(l<b.size() && b[l]==a[a.size()-1])l++;
        if (l<b.size())ok=0;
        if (ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}