#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,int> mp;
string s[1700];
string pos=  "SET";
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        mp[s[i]]=i;
    }
    ll ret=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            string need="";
            for (int x=0;x<k;x++){
                if (s[i][x]==s[j][x])need+=s[i][x];
                else {
                    char a = s[i][x], b = s[j][x];
                    char c;
                    for (int p=0;p<3;p++){
                        if (pos[p]==a || pos[p]==b)continue;
                        c=pos[p];
                        break;
                    }
                    need+=c;
                }
            }
            if (mp.find(need)!=mp.end() && mp[need]>j)ret++;
        }
    }
    cout<<ret<<endl;
}