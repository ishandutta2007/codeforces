#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[100];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        deque<char> q;
        string s;
        cin>>s;
        q.push_back(s[0]);
        vis[s[0]-'a']=1;
        int pos=0;
        bool ok=1;
        for (int i=1;i<s.size();i++){
            int v = s[i]-'a';
            if (vis[v]){
                if (pos+1<q.size() && q[pos+1]==s[i])pos++;
                else if (pos-1>=0 && q[pos-1]==s[i])pos--;
                else {
                    ok=0;
                    break;
                }
            } else {
                vis[v]=1;
                if (pos==0)q.push_front(s[i]);
                else if (pos==q.size()-1)q.push_back(s[i]),pos++;
                else {
                    ok=0;break;
                }
            }
        }
        if (ok){
            for (int i=0;i<26;i++){
                if (!vis[i])q.push_back(char(i+'a'));
            }
            string ret="";
            for (auto x:q)ret+=x;
            cout<<"YES\n"<<ret<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}