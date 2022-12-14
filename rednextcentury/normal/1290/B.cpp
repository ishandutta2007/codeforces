#include<bits/stdc++.h>
using namespace std;
#define ll long long
int num[200009][27];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s='.'+s;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<26;j++){
            num[i][j]=num[i-1][j];
        }
        num[i][s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if (s[l]!=s[r] || l==r){
            cout<<"Yes\n";
            continue;
        } else {
            int op=0;
            for (int j=0;j<26;j++){
                if (num[r][j]-num[l-1][j])op++;
                if (op>2)break;
            }
            if (op>2)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}