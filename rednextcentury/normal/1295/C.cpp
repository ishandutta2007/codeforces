#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define mid (l+r)/2
//#define L (x<<1)
//#define R (L+1)
int nxt[1000000][26];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int n=s.size();
        for (int i=s.size()-1;i>=0;i--) {
            if (i==s.size()-1){
                for (int j=0;j<26;j++){
                    nxt[i][j]=nxt[i+1][j]=n+10;
                }
            } else {
                for (int j=0;j<26;j++){
                    nxt[i][j]=nxt[i+1][j];
                }
            }
            nxt[i][s[i]-'a']=i;
        }
        int cur=0;
        int num=0;
        bool ok=1;
        for (int i=0;i<t.size();i++) {
            int v = t[i]-'a';
            if (nxt[cur][v]>n) {
                cur = 0;
                num++;
            }
            if (nxt[cur][v]>n){
                cout<<-1<<endl;
                ok=0;
                break;
            }
            cur = nxt[cur][v]+1;
        }
        if (ok)
        cout<<num+1<<endl;
    }
}